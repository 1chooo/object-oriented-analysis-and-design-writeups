# `C++` Project Templates 


## Project Structure

```
PROJECT_ROOT
├── bin/
│   └── main.out
├── include/
│   └── *.h
├── src/
│   └── *.cpp
├── test/
│   └──   :
├── build.sh
```

## How to compile with this templates?
```sh
g++ -Iinclude -o src/*.cpp -o bin/main.out && ./bin/main.out
```