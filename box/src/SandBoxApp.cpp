#include "hikaru.h"

class SandBox : public hikaru::application {
public:
	SandBox() {

	}

	~SandBox() {

	}


};

hikaru::application* hikaru::create_application() {
	return new SandBox();
}
