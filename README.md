# TW3720TU Object Oriented Scientific Programming with C++ (2017/2018 Q2)

[![pipeline status](https://gitlab.com/mmoelle1/tw3720tu.2017/badges/master/pipeline.svg)](https://gitlab.com/mmoelle1/tw3720tu.2017/commits/master)

This Git repository contains course material, examples and assignments
for the course "Object Oriented Scientific Programming with C++"
(tw3720tu) given at the Faculty of Electrical Engineering, Applied
Mathematics and Computer Sciences at Delft University of Technology in
the second quarter of the academic year 2017/2018 by Matthias Moller.

This git repository is maintained at [gitlab tw3720tu.2017].

## Getting started

Open a `Terminal` by clicking on the `Terminal icon` in the left menu.

1. Configure `git` by running
   ```
   git config --global user.name “Your Name“
   git config --global user.email you@somewhere.nl
   ```
2. Fetch the course repository by running
   ```
   git clone https://gitlab.com/mmoelle1/tw3720tu.2017
   ```
   to obtain the lecture slides, example programs and homework assignments.
   
3. Create a `build` directory and run CMake
   ```
   cd tw3720tu.2017
   mkdir build
   cd build
   cmake ..
   ```
   This will generate all required Makefiles needed to compile the examples.
   
4. Compile the example programs
   ```
   make
   ```
   
5. Run the first example program
   ```
   ./01-hello/hello
   ```

### At the end of each lab session

Save your own changes by running
```
cd tw3720tu.2017
git status
```
This will show a list of modified files, e.g., `H01-swap/src/swap.cxx`
for the first homework. Save these files by running
```
git add <filename1> <filename2> <...>
git commit -m "My homework in week 1."
```

### At the beginning of each lab session

Update your copy of the repository by running
```
cd tw3720tu.2017
git pull
```
If `git` complains about unsaved changes follow the instructions below
to change your changes.

## Additional documents

-  [Lecture schedule and assignments](SCHEDULE.md)
-  [Frequently asked questions](FAQ.md)
-  [Installation instructions](INSTALL.md)
-  [Final project](Final-project/README.md)

---

[gitlab tw3720tu.2017]: https://gitlab.com/mmoelle1/tw3720tu.2017.git
