#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <cstdlib>
#include <ctime>

class Random
{
	public:
		Random();
		Random(unsigned int seed);
		
		void setSeed(unsigned int seed);
		unsigned int getSeed() const;
		
		unsigned int nextInt() const;
		unsigned int nextInt(unsigned int max) const;
		
		double nextDouble() const;
		double nextDouble(double max) const;
	
	private:
		unsigned int seed;
};

#endif
