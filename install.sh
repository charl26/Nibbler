if brew ls --versions sdl2 > /dev/null; then
  # The package is installed
  echo "SDL2 is already installed"
else
  # The package is not installed
  echo "SDL2 installing"
  brew install sdl2
  echo "linking SDL2 library"
  brew link sdl2
fi

if brew ls --versions glfw > /dev/null; then
  # The package is installed
  echo "glfw is already installed"
else
  # The package is not installed
  echo "GLFW installing"
  brew install glfw
  echo "linking GLFW library"
  brew link glfw
fi

if brew ls --versions sfml > /dev/null; then
  # The package is installed
  echo "SFML is already installed"
else
  # The package is not installed
  echo "SFML installing"
  brew install sfml
  echo "linking SFML library"
  brew link sfml
fi