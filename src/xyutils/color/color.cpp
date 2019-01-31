#include <iostream>

using namespace std;

//int main()
//{
//    printf("\033[31mThis is RED.\n\033[0m");
//    return 0;
//}

int main() {

	cout << "\t" << "http://blog.sina.com.cn/s/blog_628ba3e00101jll1.html" << endl << endl;

	cout << endl;
	cout << "\033[2J clean screen \033[0m" << endl;
	cout << endl;

	cout << " normal" << endl;
	cout << "\033[1m highlight \033[0m" << endl;
	cout << "\033[2m highlight(half) \033[0m" << endl;
	cout << "\033[3m italic \033[0m" << endl;
	cout << "\033[4m underline \033[0m" << endl;
	cout << "\033[5m twinkle \033[0m" << endl;
	cout << "\033[6m flash \033[0m" << endl;
	cout << "\033[7m reverse \033[0m" << endl;
	cout << "\033[8m blanking \033[0m" << endl;
	cout << "\033[9m deleting \033[0m" << endl;

	cout << endl;
	cout << "\033[30m text black \033[0m" << endl;
	cout << "\033[31m text red \033[0m" << endl;
	cout << "\033[32m text green \033[0m" << endl;
	cout << "\033[33m text yellow \033[0m" << endl;
	cout << "\033[34m text blue \033[0m" << endl;
	cout << "\033[35m text purple \033[0m" << endl;
	cout << "\033[36m text green(deep) \033[0m" << endl;
	cout << "\033[37m text white \033[0m" << endl;
	cout << "\033[38m text underline open \033[0m" << endl;
	cout << "\033[39m text underline close \033[0m" << endl;

	cout << endl;
	cout << "\033[40m background black \033[0m" << endl;
	cout << "\033[41m background red \033[0m" << endl;
	cout << "\033[42m background green \033[0m" << endl;
	cout << "\033[43m background brown \033[0m" << endl;
	cout << "\033[44m background blue \033[0m" << endl;
	cout << "\033[45m background pink \033[0m" << endl;
	cout << "\033[46m background blue(peacock) \033[0m" << endl;
	cout << "\033[47m background white \033[0m" << endl;
	cout << "\033[48m background no idea \033[0m" << endl;
	cout << "\033[49m background default \033[0m" << endl;

	return 0;
}
