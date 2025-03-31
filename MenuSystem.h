#pragma once

class MenuSystem
{
public:

	MenuSystem();
	~MenuSystem();

	void display(int option) const;
	void menuLogic() const;

private:
	enum menu
	{
		menuAdd,
		menuView,
		menuDel,
		menuExit
	};
};