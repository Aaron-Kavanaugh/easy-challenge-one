#include "MENUSYSTEM.h"
#include "WriteToFile.h"
#include "ViewInfo.h"
#include "DeleteInfo.h"
#include <iostream>
#include <conio.h>

MenuSystem::MenuSystem() {}

MenuSystem::~MenuSystem() {}

// Displays the menu
void MenuSystem::display(int option) const
{
	std::cout << "=== MENU ===\n";
	std::cout << (option == menuAdd ? "> " : " ") << "Add info\n";
	std::cout << (option == menuView ? "> " : " ") << "View info\n";
	std::cout << (option == menuDel ? "> " : " ") << "Delete info\n";
	std::cout << (option == menuExit ? "> " : " ") << "Exit\n";
}

void MenuSystem::menuLogic() const
{
	WriteFile file;
	ViewInfo view;
	DeleteInfo deletefile;

	int currentOption = 0;
	char input;
	const int numOption{ 4 };
	while (true) {
		system("cls"); // needs to be "clear" on linux
		display(currentOption);

		input = _getch();

		if (input == 'w' || input == 'W')
		{
			// Move menu up
			currentOption = (currentOption > 0) ? currentOption - 1 : numOption - 1;
		}
		else if (input == 's' || input == 'S')
		{
			// Move down the menu
			currentOption = (currentOption < numOption - 1) ? currentOption + 1 : 0;
		}
		else if (input == '\r') { // press the enter key to make selection
			system("cls");
			switch (static_cast<menu>(currentOption))
			{
			case menuAdd:
				file.createFile();
				break;
			case menuView:
				view.displayInfoToConsole();
				break;
			case menuDel:
				deletefile.deleteFile();
				deletefile.deleteFile();
				break;
			case menuExit:
				std::cout << "Exited program";
				return;
			}
			system("pause"); // Pause before showing the menu again
		}
	}
}