# virtual-scene
GUI приложение, генерирующее виртуальную сцену с камерой, кубом и пирамидой (тестовое задание).

## Build

```
cmake CMakeLists.txt
make
```

## Usage

```
./virtual-scene
```

## Examples

- ...
- ...

## Docker

Пример запуска приложения в docker-контейнере:

```
docker build -t virtualscene .
docker run --network host -e DISPLAY=$DISPLAY virtualscene 
```
