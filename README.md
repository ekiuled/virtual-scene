# virtual-scene

Приложение, генерирующее виртуальную сцену с камерой, кубом и пирамидой (тестовое задание).

## Build

### Локальная сборка

```
cmake CMakeLists.txt
make
```

### Docker

Сборка контейнера с использованием `Dockerfile`. Пример:

```
docker build -t virtualscene .
docker run --network host -e DISPLAY=$DISPLAY virtualscene <parameters...>
```

## Usage

Координаты объектов и другие параметры задаются в виде параметров программы.

```
./virtual-scene camX camY camZ
                cubeX cubeY cubeZ cubeScale
                pyramidX pyramidY pyramidZ pyramidScale
```

- `camX`, `camY`, `camZ` — координаты камеры
- `cubeX`, `cubeY`, `cubeZ` — координаты куба
- `pyramidX`, `pyramidY`, `pyramidZ` — координаты пирамиды
- `cubeScale`, `pyramidScale` — размеры куба и пирамиды

## Examples

- ...
- ...
