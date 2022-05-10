# Минимальная версия CMake
cmake_minimum_required(VERSION 3.3)

# Предпочтительно следовать стандартам принятым в указанном диапазоне версий
cmake_policy(VERSION 3.0.2..3.7)

# Название и версия проекта и используемые языки программирования
project(extracting_data_from_the_site VERSION 0.3.0 LANGUAGES C CXX)

###
# Обязательные переменные для MyxCMake
###
# Название организации
set(MYX_CMAKE_ORGANIZATION_NAME "Org." CACHE STRING "")

# Имя автора
set(MYX_CMAKE_AUTHOR_NAME "John Doe" CACHE STRING "")

# Почта автора
set(MYX_CMAKE_AUTHOR_EMAIL "buk20001@mail.ru" CACHE STRING "")

# Краткое описание проекта
set(MYX_CMAKE_DESCRIPTION "Пример проекта: графическая программа Qt5" CACHE STRING "")

find_package(MyxCMake 0.4.1 REQUIRED)

# Qt5
find_package(Qt5Core COMPONENTS Private REQUIRED)
find_package(Qt5 COMPONENTS Core Sql Network REQUIRED)

# Автоматически генерируемый заголовочный файл
myx_cmake_generate_private_config_header()

# Исходные тексты программы
add_subdirectory(src/extracting_data_from_the_site_2)
