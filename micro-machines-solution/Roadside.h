
#ifndef __ROADSIDE_H__
#define  __ROADSIDE_H__

#include "Cheerio.h"


#define CHEERIO_NR_IN 40
#define CHEERIO_NR_OUT 60

class Roadside : public StaticObject {
private:
	Cheerio *cereals_in[CHEERIO_NR_IN];
	Cheerio *cereals_out[CHEERIO_NR_OUT];
public:
	Roadside();
	~Roadside();
	void draw();
};

#endif
