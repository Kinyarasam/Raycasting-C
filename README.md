# Raycasting-C
This project implements a simple raycasting engine in C, inspired by early 3D games like Wolfenstein 3D. Raycasting is a rendering technique used to create a 3D perspective in a 2D map by casting rays from the player's viewpoint and calculating intersections with the environment.

## Features
- __2D Map Rendering__: Display a simple 2D map grid representing walls and empty spaces.
- __Raycasting Alogorithm__: Calculate and render 3D walls based on ray intersections with the map
- __Player Movements__: Navigate through the environment with basic movement controls.
- __Wall texturing__: Apply textures to walls for a more realistic appearance.
- __Simple Ligting__: Implement basic lighting effects to enhance visual realism.

## Getting Started
### Prerequisites
- C compiler (GCC, Clang, etc)
- Make (optional, for build automation)
- SDL2 (for window management and rendering)

### Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/kinyarasam/Raycasting-C.git
    ```
2. Install SDL2 (if not installed):
    - on Ubuntu:
        ```bash
        sudo apt install libsdl2-dev
        ```
    - on macOS:
        ```bash
        brew install sdl2
        ```
3. Build the project.
    ```bash
    make
    ```

### Running the Project
After building, you can run the project with:
```sh
./raycasting
```

### Usage.
- Use arrow keys or `W` `A` `S` `D` to move the player.
- Press `ESC` to exit/quit the application.

## Project Structure.
- `src`: Source Code files.
- `include`: Header files.
- `assets`: Textures and other graphic assets.
- `Makefile`: Build configurations.

## Contributing
Contributions are welcome! please fork the repository and submit a pull request for any enhancements, bug fixes or new features.
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes. (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch. (`git push origin feature/AmazingFeature`)
5. Open a pull request.

## License
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) for details

## Acknowledgements
- [Lode Vandevenne's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) for foundation concepts.
- The SDL2 community for providing and excellent library for multimedia applications.
