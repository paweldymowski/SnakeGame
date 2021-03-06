#include "food.h"
#include <QDebug>
#include <QPixmap>
#include <random>

Food::Food(){
    static std::random_device generator;
    std::uniform_int_distribution<int> distribution(1,38);
    std::uniform_int_distribution<int> distribution2(1,28);

    int randomNumber1 = distribution(generator) * 20;
    int randomNumber2 = distribution2(generator) * 20;

    setPos(randomNumber1,randomNumber2);
    setPixmap(QPixmap(":/images/food.png"));

    qDebug() << "food created on position " << randomNumber1 << " x " << randomNumber2;
}

Food::~Food(){
    qDebug() << "food destructed";
}


