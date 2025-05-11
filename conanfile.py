from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout
from conan.tools.microsoft import VCVars

required_conan_version = "^2.16.1"


class MyProjectConan(ConanFile):
    name = "my_proj"
    version = "1.0.1"
    author = "Stepan Zorin"

    settings = "arch", "build_type", "compiler", "os"
    generators = "CMakeDeps", "CMakeToolchain"

    def configure(self):
        self.options["boost"].without_cobalt = True
        self.options["boost"].extra_b2_flags = "--hash"

    def requirements(self):  # [ FORWARD SORT BY PACKAGE NAME ]
        # third-party packages
        self.requires("boost/1.87.0")
        self.requires("spdlog/1.15.1")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def layout(self):
        cmake_layout(self)