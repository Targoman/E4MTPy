import setuptools
from setuptools.dist import Distribution


# Tested with wheel v0.29.0
class BinaryDistribution(Distribution):
    """Distribution which always forces a binary package with platform name"""
    def has_ext_modules(foo):
        return True

setuptools.setup(
    name="E4MTPy", 
    version="0.1.0",
    author="Targoman Intelligent Processing Co. Pjc.",
    author_email="info@targoman.com",
    description="An Essential text processor for Machine translation task",
    url="https://github.com/Targoman/E4MT",
    project_urls={"": "",},
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: GNU License",
        "Operating System :: POSIX :: Linux"
    ],
    package_dir={"": "src"},
    packages=setuptools.find_packages(where="src"),
    python_requires=">=3",
    include_package_data=True,
    package_data={'E4MTPy': ['*.so*']},
    platforms=['posix'],
    distclass=BinaryDistribution
)
