#include <iostream>
#include <string>

enum VendingMachineState
{
	SELECT, QUANTITY, CALCULATE, UPDATE
};

enum Brand
{
	COKE = 401, PEPSI, SEVENUP
};

struct Student
{
	std::string name;
	int cash;
};

struct Soda
{
	Brand brandName;
	int inventory;
	int price;
};

int main()
{
	// Initial Vending Machine State is SELECT. Update upon state change.
	VendingMachineState currentState = SELECT;

	// Fill up vending machine with Sodas
	Soda vendingMachine[3];

	// Load up with COKE
	vendingMachine[0].brandName = COKE;
	vendingMachine[0].inventory = 10;
	vendingMachine[0].price = 20;

	// Load up with PEPSI
	vendingMachine[1].brandName = PEPSI;
	vendingMachine[1].inventory = 10;
	vendingMachine[1].price = 25;

	// Load up with SEVENUP
	vendingMachine[2].brandName = SEVENUP;
	vendingMachine[2].inventory = 10;
	vendingMachine[2].price = 30;

	Soda selectedSoda;
	Student abhi;
	abhi.name = "Abhi";
	abhi.cash = 200; // 200 cash amount at first

	while (true)
	{
		switch (currentState)
		{
		case SELECT:

			// 1. Display Vending Machine status and User's wallet amount.
			std::cout << "<<<<<-----CURRENT STATUS----->>>>>" << std::endl;
			std::cout << "[[[Vending Machine]]]" << std::endl;
			for (int i = 0; i < sizeof(vendingMachine) / 12; i++)	// each Soda item takes 12 bytes of space
			{
				std::cout << vendingMachine[i].brandName << " has " << vendingMachine[i].inventory << " drinks left, and each costs " << vendingMachine[i].price << " dollars" << std::endl;

			}

			std::cout << "[[[User]]]" << std::endl;
			std::cout << abhi.name << " has " << abhi.cash << " left total" << std::endl;
			std::cout << "<<<<<-----END STATUS----->>>>>" << std::endl << std::endl;

			// 2. Ask the user what drink they want.
			std::cout << "Please select a drink from the following available options." << std::endl;

			// 3. Display Soda names and corresponding ID values.
			std::cout << "COKE = 401\nPEPSI = 402\nSEVENUP = 402" << std::endl;

			// 4. User inputs the drink.
			int selectedDrink;
			std::cin >> selectedDrink;

			// 5. If valid drink selected, move to QUANTITY state, else, go back to SELECT state.
			switch (selectedDrink)
			{
			case COKE:
				std::cout << "You have selected COKE" << std::endl;
				selectedSoda.brandName = COKE;
				currentState = QUANTITY;
				break;

			case PEPSI:
				std::cout << "You have selected PEPSI" << std::endl;
				selectedSoda.brandName = PEPSI;
				currentState = QUANTITY;
				break;

			case SEVENUP:
				std::cout << "You have selected SEVENUP" << std::endl;
				selectedSoda.brandName = SEVENUP;
				currentState = QUANTITY;
				break;

			default:
				std::cout << "Invalid drink selected!" << std::endl;
				currentState = SELECT;
				break;
			}
			break;

		case QUANTITY:

			std::cout << "How many drinks would you like?";
			int orderQuantity;
			std::cin >> orderQuantity;
			std::cout << "You placed an order for " << orderQuantity << " soda(s)." << std::endl;

			switch (selectedSoda.brandName)
			{
			case COKE:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[0].inventory) {
					std::cout << "Not enough " << selectedSoda.brandName << " in stock" << std::endl;
					currentState = SELECT;
					std::cout << std::endl << std::endl;
				}
				else {
					currentState = CALCULATE;
				}
				break;

			case PEPSI:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[1].inventory) {
					std::cout << "Not enough " << selectedSoda.brandName << " in stock" << std::endl;
					currentState = SELECT;
					std::cout << std::endl << std::endl;
				}
				else {
					currentState = CALCULATE;
				}
				break;

			case SEVENUP:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[2].inventory) {
					std::cout << "Not enough " << selectedSoda.brandName << " in stock" << std::endl;
					currentState = SELECT;
					std::cout << std::endl << std::endl;
				}
				else {
					currentState = CALCULATE;
				}
				break;

			default:
				std::cout << "Invalid Amount Received" << std::endl;
				break;

			}

			break;

		case CALCULATE:

			std::cout << "The total cost for your soda is: ";
			int cost;

			switch (selectedSoda.brandName)
			{
			case COKE:
				cost = vendingMachine[0].price * orderQuantity;
				std::cout << cost << std::endl;
				break;
			case PEPSI:
				cost = vendingMachine[1].price * orderQuantity;
				std::cout << cost << std::endl;
				break;
			case SEVENUP:
				cost = vendingMachine[2].price * orderQuantity;
				std::cout << cost << std::endl;
				break;
			default:
				std::cout << "Error!" << std::endl;
				break;
			}

			int payment;
			std::cout << "Please type in your payment: ";
			std::cin >> payment;

			if (payment > abhi.cash || payment < cost || payment <= 0) {
				std::cout << "You don't have enough money!" << std::endl;
				currentState = SELECT;
				std::cout << std::endl << std::endl;
			}
			else {
				abhi.cash -= payment;
				int change = payment - cost;
				std::cout << "Thank you! Your change is: " << change << "." << std::endl;
				abhi.cash += change;
				currentState = UPDATE;
			}
			break;

		case UPDATE:

			switch (selectedSoda.brandName)
			{
			case COKE:
				vendingMachine[0].inventory -= orderQuantity;
				currentState = SELECT;
				std::cout << std::endl << std::endl;
				break;
			case PEPSI:
				vendingMachine[1].inventory -= orderQuantity;
				currentState = SELECT;
				std::cout << std::endl << std::endl;
				break;
			case SEVENUP:
				vendingMachine[2].inventory -= orderQuantity;
				currentState = SELECT;
				std::cout << std::endl << std::endl;
				break;
			default:
				std::cout << "Error" << std::endl;
				currentState = SELECT;
				std::cout << std::endl << std::endl;
				break;
			}
			std::cout << "Inventory Updated" << std::endl;
			currentState = SELECT;
			std::cout << std::endl << std::endl;

			break;
			 
		default:
			std::cout << "Error! Invalid State Detected." << std::endl;
			break;
		}
	}

	system("pause");
	return 0;
}