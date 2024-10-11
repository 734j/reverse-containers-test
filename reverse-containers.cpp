#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <unistd.h>
#include <cstring>
#define CONTAINER_SIZE 1048576
char *g_argv = nullptr;
inline void usageOUT() {
	std::cerr << g_argv << " [-1][-2][-3][-4][-5][-6][-7]" << std::endl;
}

std::vector<char> &reverse_vector_reverse_iterator(std::vector<char> &vc) {

	auto size_vc = vc.size();
	std::vector<char> tmp_vc(size_vc);
	auto vc_rbeg = vc.rbegin();
	auto vc_rend = vc.rend();
	for(auto &a : tmp_vc) {
		if(vc_rbeg == vc_rend) {
			break;
		}
		a = *vc_rbeg++;
	}

	vc = tmp_vc;
	return vc;
}

std::vector<char> &reverse_vector_no_tmp_iterators(std::vector<char> &vc) {

	auto r_beg = vc.rbegin();
	auto beg = vc.begin();
	for(decltype(vc.size()) a = 0 ; a != (vc.size() / 2) ; ++a, ++beg, ++r_beg) {
		char tmp = *beg;
		*beg = *r_beg;
		*r_beg = tmp;
	}
	
	return  vc;
}

std::vector<char> &reverse_vector_construct_swap(std::vector<char> &vc) {

	std::vector tmp_vc(vc.crbegin(), vc.crend());
	vc.swap(tmp_vc);
	return vc;
}

std::vector<char> &reverse_vector_subscript(std::vector<char> &vc) {

	auto imax = vc.size()-1;
	for(decltype(vc.size()) i = 0 ; i != (vc.size() / 2) ; ++i, --imax) {
		char tmp = vc[i];
		vc[i] = vc[imax];
		vc[imax] = tmp;
	}
	
	return vc;
}

std::deque<char> &reverse_deque_no_tmp_iterators(std::deque<char> &dc) {

	auto rbeg = dc.rbegin();
	auto beg = dc.begin();
	for(decltype(dc.size()) i = 0 ; i != (dc.size() / 2) ; ++i, ++beg, ++rbeg) {
		char tmp = *beg;
		*beg = *rbeg;
		*rbeg = tmp;
	}
	
	return dc;
}

std::deque<char> &reverse_deque_construct_swap(std::deque<char> &dc) {

	std::deque<char> tmp_dc(dc.crbegin(), dc.crend());
	dc.swap(tmp_dc);
	return dc;
}

char *reverse_cstring(const char *cstr, char cstr2[CONTAINER_SIZE]) {

	auto max_len = std::strlen(cstr) -1;
	for(size_t i = 0 ; cstr[i] != '\0' && i != CONTAINER_SIZE ; ++i, --max_len) {
		cstr2[i] = cstr[max_len];
	}
	
	return cstr2;
}

std::string &reverse_string_construct_swap(std::string &sc) {

	std::string tmp_sc(sc.crbegin(), sc.crend());
	sc.swap(tmp_sc);
	return sc;
}

std::string &reverse_string_no_tmp_iterators(std::string &sc) {

	auto rbeg = sc.rbegin();
	auto beg = sc.begin();
	for(decltype(sc.size()) i = 0 ; i != (sc.size() / 2); ++i, ++beg, ++rbeg) {
		char tmp = *beg;
		*beg = *rbeg;
		*rbeg = tmp;
	}
	
	return sc;
}

std::list<char> &reverse_list(std::list<char> &lc) {

	auto beg = lc.begin();
	auto crbeg = lc.crbegin();
	for(decltype(lc.size()) i = 0 ; i != (lc.size() / 2) ; ++i, ++crbeg) {
		lc.insert(beg, *crbeg);
	}

	lc.erase(++beg, lc.cend());
	return lc;
}

std::array<char, CONTAINER_SIZE> &reverse_array(std::array<char, CONTAINER_SIZE> &ac) {
	// This function is a little weird, not sure if i like it...
	std::array<char, CONTAINER_SIZE> tmp_ac;
	auto crbeg = ac.crbegin();
	auto begin = tmp_ac.begin();
	for( ; begin != tmp_ac.cend() ; ++crbeg, ++begin) {
		*begin = *crbeg;
	}

	ac.swap(tmp_ac);
	return ac;
}

void print_container(std::array<char, CONTAINER_SIZE> &ac) {

	for(auto &b : ac) {
		std::cout << b << " ";
	}
	
	std::cout << std::endl;
}

void print_container(std::string &sc) {

	std::cout << sc << std::endl;
}

void print_container(const char *ap) {

	std::cout << ap;	
	std::cout << std::endl;
}

void print_container(std::vector<char> &vc) {

	for(auto &b : vc) {
		std::cout << b << " ";
	}
	
	std::cout << std::endl;
}

void print_container(std::list<char> &lc) {

	for(auto &b : lc) {
		std::cout << b << " ";
	}
	
	std::cout << std::endl;
}


void print_container(std::deque<char> &dc) {

	for(auto &b : dc) {
		std::cout << b << " ";
	}
	
	std::cout << std::endl;
}

int main(int argc, char **argv) {

	g_argv = argv[0];
	if(argc < 2 || argc > 2) {
		usageOUT();
		return EXIT_FAILURE;
	}
	
	int opt;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	int zero = 0;
	int a_letter = 0;
    while ((opt = getopt(argc, argv, "1234567890a")) != -1) {
        switch (opt) {
        case '1':

			one = 1;

			break;
        case '2':

			two = 1;

			break;
		case '3':

			three = 1;

			break;
		case '4':

			four = 1;

			break;
		case '5':

			five = 1;

			break;
		case '6':

			six = 1;

			break;
		case '7':

			seven = 1;

			break;
		case '8':

			eight = 1;
			
			break;
		case '9':

			nine = 1;

			break;
		case '0':

			zero = 1;
			
			break;
		case 'a':

			a_letter = 1;
			
			break;
		}
	}

	if((one + two + three + four + five + six + seven + eight + nine + zero + a_letter) > 1) {
		usageOUT();
		return EXIT_FAILURE;
	}

	std::array<char, CONTAINER_SIZE> input_array = {'a', 'b'};
	std::string input_str = "ab";
	const char *input_cstr = "ab";
	std::list<char> input_list = {'a', 'b'};
	std::vector<char> input_vec = {'a', 'b'};
	std::deque<char> input_deq = {'a', 'b'};
 	if(one == 1) {
		reverse_vector_reverse_iterator(input_vec);
		print_container(input_vec);
		std::cout << "reverse_vector_reverse_iterator" << std::endl;
	}

	if(two == 1) {
		reverse_vector_no_tmp_iterators(input_vec);
		print_container(input_vec);
		std::cout << "reverse_vector_no_tmp_iterators" << std::endl;
	}

	if(three == 1) {
		reverse_vector_construct_swap(input_vec);		
		print_container(input_vec);
		std::cout << "reverse_vector_construct_swap" << std::endl;
	}

	if(four == 1) {
		reverse_vector_subscript(input_vec);
		print_container(input_vec);
		std::cout << "reverse_vector_subscript" << std::endl;
	}

	if(five == 1) {
		reverse_deque_no_tmp_iterators(input_deq);
		print_container(input_deq);
		std::cout << "reverse_deque_no_tmp_iterators" << std::endl;
	}

	if(six == 1) {
		reverse_deque_construct_swap(input_deq);
		print_container(input_deq);
		std::cout << "reverse_deque_construct_swap" << std::endl;
	}

	if(seven == 1) {
		char cstr2[CONTAINER_SIZE];
		cstr2[0] = '\0';
		reverse_cstring(input_cstr, cstr2);
		print_container(cstr2);
		std::cout << "reverse_cstring" << std::endl;
	}

	if(eight == 1) {
		reverse_string_construct_swap(input_str);
		print_container(input_str);
		std::cout << "reverse_string_construct_swap" << std::endl;
	}

	if(nine == 1) {
		reverse_string_no_tmp_iterators(input_str);
		print_container(input_str);
		std::cout << "reverse_string_no_tmp_iterators" << std::endl;
	}

	if(zero == 1) {
		reverse_list(input_list);
		print_container(input_list);
		std::cout << "reverse_list" << std::endl;
	}

	if(a_letter == 1) {
		reverse_array(input_array);
		print_container(input_array);
		std::cout << "" << std::endl;
	}
	
	return 0;
}
