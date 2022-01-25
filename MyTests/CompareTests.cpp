#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#define TYPE_COLOR "\033[38;2;255;255;0m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

void	compare(std::string fileName1, std::string fileName2){
	std::ifstream f1("./allResult/"+fileName1+".txt"), f2("./allResult/"+fileName2+".txt");
	if (f1.is_open() && f2.is_open()){
		std::string s1, s2;
		while (getline(f1, s1) && getline(f2, s2))
			if (s1 != s2){
				if (s1[0] != '-')
					std::cout<<TYPE_COLOR;
				std::cout<<s1<<std::setw(100)<<s2<<RESET_COLOR<<std::endl;
			}
	}
	f1.close();
	f2.close();
}

int		main(){
	std::time_t t1 = std::time(nullptr);
	FILE *exStd = popen("./stdExec", "r");
	std::time_t t2 = std::time(nullptr);
	pclose(exStd);
	std::cout<<"stdTime = "<<std::time(&t2) - std::time(&t1)<<std::endl;

	t1 = std::time(nullptr);
	FILE *exFt = popen("./FtExec", "r");
	t2 = std::time(nullptr);
	pclose(exFt);
	std::cout<<"ftTime = "<<std::time(&t2) - std::time(&t1)<<std::endl;

	compare("stdStack", "ftStack");
	compare("stdVector", "ftVector");
	compare("stdMap", "ftMap");
	return (0);
}