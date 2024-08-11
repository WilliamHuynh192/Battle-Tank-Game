from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake, CMakeDeps


class BattleTankRecipe(ConanFile):
    name = "battle_tank"
    version = "1.0"
    package_type = "application"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    exports_sources = "CMakeLists.txt", "src/*", "textures/*"

    def requirements(self):
        self.requires("sdl/2.30.5", force=True) # Temporary fix with "force" because sdl_image/2.6.3 has a dep older sdl
        self.requires("sdl_image/2.6.3")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def build_requirements(self):
        self.tool_requires("cmake/3.30.1")

    def package(self):
        cmake = CMake(self)
        cmake.install()
