#include "hikaru.h"

class SandBox : public hikaru::Application {
public:
	SandBox() {

	}

	~SandBox() {

	}


};

hikaru::Application* hikaru::create_application() {
	return new SandBox();
}
