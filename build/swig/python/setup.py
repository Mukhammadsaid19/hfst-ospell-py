import setuptools.command.install
import shutil
from distutils.sysconfig import get_python_lib


class CompiledLibInstall(setuptools.command.install.install):
    """
    Specialized install to install to python libs
    """

    def run(self):
        """
        Run method called by setup
        :return:
        """
        # Get filenames from CMake variable
        filenames = '/home/place2play/swig/swig-example/build/swig/python/swig_example.py;/home/place2play/swig/swig-example/build/swig/python/_swig_example.so'.split(';')

        # Directory to install to
        install_dir = get_python_lib()

        # Install files
        [shutil.copy(filename, install_dir) for filename in filenames]


if __name__ == '__main__':
    setuptools.setup(
        name='swig_example',
        version='1.0.0-dev',
        packages=['swig_example'],
        license='Apache License 2.0',
        author='Daniel Underwood',
        author_email='daniel.underwood13@gmail.com',
        cmdclass={'install': CompiledLibInstall}
    )
