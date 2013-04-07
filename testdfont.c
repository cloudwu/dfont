#include "dfont.h"

static void
test(struct dfont *df) {
	int i,j;
	for (i=0;i<20;i++) {
		for (j=0;j<4;j++) {
			dfont_insert(df, i, 12+i/2+j , 16+j, 0);
		}
	}
	dfont_dump(df);
	dfont_flush(df);
	for (i=0;i<10;i++) {
		dfont_insert(df, 100+i, 12+i+j , 16+i%4, 0);
	}
	dfont_dump(df);
}

int
main() {
	struct dfont *df = dfont_create(128,128);
	test(df);
	dfont_release(df);
	return 0;
}
