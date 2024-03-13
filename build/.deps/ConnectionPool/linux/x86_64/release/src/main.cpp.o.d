{
    depfiles_gcc = "main.o: src/main.cpp include/connection.h\
",
    files = {
        "src/main.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-Iinclude"
        }
    }
}