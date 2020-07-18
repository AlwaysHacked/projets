#!bin/bash

echo "Avant de vous y lancer quelques petites questions

Quelles voulez vous que les dimensions soient? "
echo -n "X: "; read X
echo -n "Y: "; read Y
sed -i "s/static const short X = .*, Y = .*;/static const short X = ${X}, Y = ${Y};/g" donnee.hpp 

echo "Et les probabilites?"
echo -n "Probabilite de termite (sur 100):    "; read proba_t
echo -n "Probabilite de brindilles (sur 100): "; read proba_b
sed -i "s/static const unsigned short proba_t = .*, proba_b = .*;/static const unsigned short proba_t = ${proba_t}, proba_b = ${proba_b};/g" donnee.hpp
echo


