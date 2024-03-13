target("ConnectionPool")
set_kind("binary")
add_links("mysqlclient")
add_includedirs("include")
add_files("src/*.cpp")

set_rundir("$(projectdir)")
