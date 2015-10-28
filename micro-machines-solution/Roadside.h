
#ifndef __ROADSIDE_H__
#define  __ROADSIDE_H__
#include <math.h>
#include "Cheerio.h"


#define CHEERIO_NR_OUT 60
#define CHEERIO_NR_IN 40
#define LIMIT		  0.25
class Roadside : public StaticObject {
private:
	Cheerio *cereals_in[CHEERIO_NR_IN];
	Cheerio *cereals_out[CHEERIO_NR_OUT];
public:
	Roadside();
	~Roadside();
	void draw();
	void update(double);
	bool  checkHit(GameObject*) override;
};

#endif
