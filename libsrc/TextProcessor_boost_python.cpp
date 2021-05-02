/******************************************************************************
 * Targoman: A robust Machine Translation framework               *
 *                                                                            *
 * Copyright 2014-2018 by ITRC <http://itrc.ac.ir>                            *
 *                                                                            *
 * This file is part of Targoman.                                             *
 *                                                                            *
 * Targoman is free software: you can redistribute it and/or modify           *
 * it under the terms of the GNU Lesser General Public License as published   *
 * by the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                        *
 *                                                                            *
 * Targoman is distributed in the hope that it will be useful,                *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU Lesser General Public License for more details.                        *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with Targoman. If not, see <http://www.gnu.org/licenses/>.           *
 *                                                                            *
 ******************************************************************************/
/**
 * @author Zakieh Shakeri <z.shakeri@targoman.com>
 * @author Behrooz Vedadian <vedadian@targoman.com>
 */

#include <string.h>
#include <boost/python.hpp>
using namespace boost::python;

bool c_init(
        const std::string _normalizationFilePath,
        const std::string _abbreviationFilePath,
        const std::string _spellCorrectorBaseConfigPath,
        const boost::python::list _languages
        );
std::string c_ixml2Text(
                const std::string _source,
                bool _detokenize=false,
                bool _hinidiDigits=true,
                bool _arabicPunctuations=true,
                bool _breakSentences=false);
std::string c_text2IXML(
                const std::string _source,
                const std::string _language,
                bool _useSpellCorrector=true);
std::string c_tokenize(
                const std::string _source,
                const std::string _language,
                bool _useSpellCorrector=true,
                bool _hinidiDigits=true,
                bool _arabicPunctuations=true,
                bool _breakSentences=false);
std::string c_normalize(
    const std::string _source
    );

BOOST_PYTHON_FUNCTION_OVERLOADS(c_ixml2Text_overloads, c_ixml2Text, 1, 5)
BOOST_PYTHON_FUNCTION_OVERLOADS(c_text2IXML_overloads, c_text2IXML, 2, 3)
BOOST_PYTHON_FUNCTION_OVERLOADS(c_tokenize_overloads, c_tokenize, 2, 6)
BOOST_PYTHON_MODULE(libE4MTPy)
{
    def("init", c_init);
    def("normalize", c_normalize);
    def("tokenize", &c_tokenize, c_tokenize_overloads(
                                            (arg("_source"), 
                                            arg("_language"),
                                            arg("_useSpellCorrector")=true,
                                            arg("_hinidiDigits")=true,
                                            arg("_arabicPunctuations")=true,
                                            arg("_breakSentences")=false
                                            )));
    def("text2IXML", &c_text2IXML, c_text2IXML_overloads(
                                            (arg("_source"), 
                                            arg("_language"),
                                            arg("_useSpellCorrector")=true
                                            )));
    def("ixml2Text", &c_ixml2Text, c_ixml2Text_overloads(
                                            (arg("_source"), 
                                            arg("_detokenize")=false,
                                            arg("_hinidiDigits")=true,
                                            arg("_arabicPunctuations")=true,
                                            arg("_breakSentences")=false
                                            )));
}

#include <QtCore>
#include "libTargomanTextProcessor/TextProcessor.h"
#include "libTargomanCommon/Logger.h"

using namespace Targoman::Common;
using namespace Targoman::NLPLibs;

bool c_init(
        const std::string _normalizationFilePath,
        const std::string _abbreviationFilePath,
        const std::string _spellCorrectorBaseConfigPath,
        const boost::python::list _languages
        ) {

    Targoman::Common::TARGOMAN_IO_SETTINGS.setSilent();
    
    TargomanTextProcessor::stuConfigs Configs;

    Configs.NormalizationFile = QString::fromUtf8(_normalizationFilePath.data());
    Configs.AbbreviationsFile = QString::fromUtf8(_abbreviationFilePath.data());
    Configs.SpellCorrectorBaseConfigPath = QString::fromUtf8(_spellCorrectorBaseConfigPath.data());
    
    unsigned short n = len(_languages);
    if(n > 0) {
        for (int i = 0; i < n; ++i){
            QVariantHash SpellCorrector;
            SpellCorrector.insert("Active", true);
            std::string l = boost::python::extract<std::string>(_languages[i]);
            Configs.SpellCorrectorLanguageBasedConfigs.insert(QString::fromUtf8(l.data()), SpellCorrector);
        }
    }

    TargomanTextProcessor::instance().init(Configs);

    return true;
}

std::string c_ixml2Text(const std::string _source,
                 bool _detokenize,
                 bool _hinidiDigits,
                 bool _arabicPunctuations,
                 bool _breakSentences) {
    QString Source = QString::fromUtf8(_source.data());
    QString Result = TargomanTextProcessor::instance().ixml2Text(Source, _detokenize, _hinidiDigits, _arabicPunctuations, _breakSentences);
    return Result.toStdString();
}

std::string c_text2IXML(const std::string _source, const std::string _language, bool _useSpellCorrector) {
    QString Source = QString::fromUtf8(_source.data());
    QString Language = QString::fromUtf8(_language.data());
    bool SpellCorrected = false;
    QString Result = TargomanTextProcessor::instance().text2IXML(
        Source,
        SpellCorrected,
        Language,
        0,
        false,
        _useSpellCorrector,
        QList<enuTextTags::Type>(),
        QList<stuIXMLReplacement>()
        );
    return Result.toStdString();
}

std::string c_tokenize(const std::string _source,
                const std::string _language,
                bool _useSpellCorrector,
                bool _hinidiDigits,
                bool _arabicPunctuations,
                bool _breakSentences) {
    QString Source = QString::fromUtf8(_source.data());
    QString Language = QString::fromUtf8(_language.data());
    bool SpellCorrected = false;
    QString Result = TargomanTextProcessor::instance().ixml2Text(
        TargomanTextProcessor::instance().text2IXML(
            Source,
            SpellCorrected,
            Language,
            0,
            false,
            _useSpellCorrector,
            QList<enuTextTags::Type>(),
            QList<stuIXMLReplacement>()
            ),
        false,
        _hinidiDigits,
        _arabicPunctuations,
        _breakSentences
        );
    return Result.toStdString();
}

std::string c_normalize(const std::string _source) {
    QString Source = QString::fromUtf8(_source.data());
    bool SpellCorrected = false;
    QString Result = TargomanTextProcessor::instance().normalizeText(
        Source,
        SpellCorrected,
        "");
    return Result.toStdString();
}
