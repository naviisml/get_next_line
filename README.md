# C Boilerplate

This is a C Boilerplate for my future C projects on Codam. This boilerplate allows me to start projects swiftly with a pre-made template.

To use this boilerplate, simply edit the basic configuration in the Makefile and add your files to the SOURCE_FILES list. After that, run the ’all‘ command.

## Requirements

- Make
- C

## Commands

To build the program in the final stage, the `all` rule as followed in a terminal;
```
make all
```

To build the final script, and run it after compilation, you may use the `dev` command used as followed in a terminal;
```
make dev
```

To clean up the `objects/` files and folder, you can use the `clean` command as followed in a terminal;
```
make clean
```

To remove both the `objects/` files, the `build` files and the compiled program file, you can simply use the `fclean` command as followed in a terminal;
```
make fclean
```
