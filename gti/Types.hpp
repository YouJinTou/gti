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

	inline bool operator==(const Move & other)
	{
		return (from == other.from && to == other.to);
	}
};

#endif // !TYPES_HPP
