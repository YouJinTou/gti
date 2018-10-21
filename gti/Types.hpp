#ifndef TYPES_HPP
#define TYPES_HPP

struct Move
{
	Move(int from, int to) :
		from{ from },
		to{ to }
	{
	}

	int from;
	int to;
};


#endif // !TYPES_HPP
