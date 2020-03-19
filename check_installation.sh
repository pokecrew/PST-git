#!/bin/sh



echo "Etat installation libsdl1.2debian :" && dpkg -s libsdl1.2debian | grep Status && echo "\n"
echo "Etat installation libsdl-mixer1.2 :" && dpkg -s libsdl-mixer1.2 | grep Status && echo "\n"
echo "Etat installation libfreetype6 :" && dpkg -s libfreetype6 | grep Status && echo "\n"
echo "Etat installation libsdl-ttf2.0-0 :" && dpkg -s libsdl-ttf2.0-0 | grep Status && echo "\n"
echo "Etat installation libsdl-image1.2 :" && dpkg -s libsdl-image1.2 | grep Status && echo "\n"
#echo "Etat installation libsdl1.2-dev :" && dpkg -s libsdl1.2-dev | grep Status && echo "\n"
#echo "Etat installation libsdl-mixer1.2-dev :" && dpkg -s libsdl-mixer1.2-dev | grep Status && echo "\n"
#echo "Etat installation libsdl-ttf2.0-dev :" && dpkg -s libsdl-ttf2.0-dev | grep Status && echo "\n"
#echo "Etat installation libsdl-image1.2-dev :" && dpkg -s libsdl-image1.2-dev | grep Status && echo "\n"
