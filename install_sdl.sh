#!/bin/sh

  echo "Installation libsdl1.2debian :" && sudo apt-get install libsdl1.2debian && echo "\n"
  echo "Installation libsdl-mixer1.2 :" && sudo apt-get install libsdl-mixer1.2 && echo "\n"
  echo "Installation libfreetype6 :" && sudo apt-get install libfreetype6  && echo "\n"
  echo "Installation libsdl-image1.2 :" && sudo apt-get install libsdl-image1.2  && echo "\n"
  echo "Installation libsdl-ttf2.0-0 :" && sudo apt-get install libsdl-ttf2.0-0 && echo "\n"
  #echo "Installation libsdl1.2-dev :" && sudo apt-get install libsdl1.2-dev && echo "\n"
  #echo "Installation libsdl-mixer1.2-dev :" && sudo apt-get install libsdl-mixer1.2-dev && echo "\n"
  #echo "Installation libsdl-ttf2.0-0-dev :" && sudo apt-get install libsdl-ttf2.0-dev && echo "\n"
  #echo "Installation libsdl-image1.2-dev :" && sudo apt-get install libsdl-image1.2-dev  && echo "\n"

  ./check_installation.sh
