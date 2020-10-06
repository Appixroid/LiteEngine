#include "Random.h"

Random::Random() : Random(time(NULL)) {}

Random::Random(unsigned int seed)
{
	this->setSeed(seed);
}

void Random::setSeed(unsigned int seed)
{
	this->seed = seed;
	srand(seed);
}

unsigned int Random::getSeed() const
{
	return this->seed;
}

unsigned int Random::nextInt() const
{
	return rand();
}

unsigned int Random::nextInt(unsigned int max) const
{
	return this->nextInt() % max+1;
}

double Random::nextDouble() const
{
	return (double) rand() / (double) RAND_MAX;
}

double Random::nextDouble(double max) const
{
	return this->nextDouble() * max;
}
