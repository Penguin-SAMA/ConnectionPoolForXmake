{
    files = {
        "src/connectionPool.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-Iinclude"
        }
    },
    depfiles_gcc = "connectionPool.o: src/connectionPool.cpp\
"
}