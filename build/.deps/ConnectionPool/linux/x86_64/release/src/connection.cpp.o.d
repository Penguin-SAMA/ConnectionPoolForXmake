{
    depfiles_gcc = "connection.o: src/connection.cpp include/connection.h include/public.h\
",
    files = {
        "src/connection.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-Iinclude"
        }
    }
}