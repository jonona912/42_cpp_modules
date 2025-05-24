#include "Harl.hpp"

#include <iostream>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << "Usage ./harlFilter \"Complaint\"" << std::endl;
		return 0;
	}
	std::string inputComplaint = argv[1];
	if (inputComplaint.empty()) {
		std::cout << "Empty complaint. Harl is not that crazy" << std::endl;
		return 0;
	}
	Harl harlFilter;
	// harlFilter.complaintCrazeMode(inputComplaint);
	int i = harlFilter.returnComplaintNum(inputComplaint);
	switch (i) {
		case 0:
			harlFilter.executeComplaint(0);
			// fallthrough
		case 1:
			harlFilter.executeComplaint(1);
			// fallthrough
		case 2:
			harlFilter.executeComplaint(2);
			// fallthrough
		case 3:
			harlFilter.executeComplaint(3);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
