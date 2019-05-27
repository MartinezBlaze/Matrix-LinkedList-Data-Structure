#include <iostream>

using namespace std;

class ColumnNode
{
public:
	int columnIndex;

	int info;
	ColumnNode* link;
};

class RowNode
{
public:
	int rowIndex;

	RowNode* link;

	ColumnNode* head;
	int size;

	RowNode();

	~RowNode();

	void insertAtBeginning(int value, int columnIndex);

	void insertAtEnd(int value, int columnIndex);

	void insertItemAt(int value, int columnIndex);

	bool searchItem(int columnIndex);

	int getItemAt(int columnIndex);

	ColumnNode* getColumnAt(int columnIndex);

	void setItemAt(int value, int columnIndex);

	void deleteItemFirst();

	void deleteItemLast();
	
	void deleteItemAt(int index);
};

RowNode::RowNode()
{
	this->size = 0;
	this->head = NULL;
}

RowNode::~RowNode()
{
	ColumnNode* current = head;
	while (head != NULL)
	{
		current = current->link;
		delete head;
		head = current;
	}
}

void RowNode::insertAtBeginning(int value, int columnIndex)
{
	ColumnNode* newNode = new ColumnNode;
	newNode->columnIndex = columnIndex;
	newNode->info = value;
	newNode->link = head;
	head = newNode;
	size++;
}

void RowNode::insertAtEnd(int value, int columnIndex)
{
	ColumnNode* newNode = new ColumnNode;
	newNode->columnIndex = columnIndex;
	newNode->info = value;
	newNode->link = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		ColumnNode* last = head;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = newNode;
	}
	this->size++;
}

void RowNode::insertItemAt(int value, int columnIndex)
{
	ColumnNode* newNode = new ColumnNode;
	newNode->columnIndex = columnIndex;
	newNode->info = value;
	ColumnNode* prev = head;

	bool placedInBetween = false;

	for (int i = 0; i < size; i++)
	{
		if (prev->columnIndex > columnIndex)
		{
			placedInBetween = true;
			break;
		}
		prev = prev->link;
	}

	if (placedInBetween == true)
	{
		newNode->link = prev->link;
		prev->link = newNode;
		size++;
	}
	else
	{
		insertAtEnd(value, columnIndex);
	}
}

bool RowNode::searchItem(int columnIndex)
{
	ColumnNode* current = head;
	while (current != NULL)
	{
		if (current->columnIndex == columnIndex)
		{
			return true;
		}
		else
		{
			current = current->link;
		}
	}
	return false;
}

int RowNode::getItemAt(int columnIndex)
{
	if (columnIndex < 0)
	{
		cout << "Cannot use negative index.\n";
	}
	ColumnNode* current = head;

	bool itemFound = false;

	for (int i = 0; i < size; i++)
	{
		if (current->columnIndex == columnIndex)
		{
			itemFound = true;
			return current->info;
		}
		current = current->link;
	}

	// if after iterating item not found
	if (itemFound == false)
	{
		return 0;
	}
}

ColumnNode* RowNode::getColumnAt(int columnIndex)
{
	if (rowIndex < 0)
	{
		cout << "Cannot use negative index.\n";
	}
	ColumnNode* current = head;

	bool itemFound = false;

	for (int i = 0; i < size; i++)
	{
		if (current->columnIndex == columnIndex)
		{
			itemFound = true;
			return current;
		}
		current = current->link;
	}

	// if after iterating item not found
	if (itemFound == false)
	{
		return NULL;
	}
}

void RowNode::setItemAt(int value, int columnIndex)
{
	if (columnIndex < 0)
	{
		cout << "Cannot use negative index.\n";
	}
	ColumnNode* current = head;

	bool itemFound = false;

	for (int i = 0; i < size; i++)
	{
		if (current->columnIndex == columnIndex)
		{
			itemFound = true;
			current->info = value;
			cout << "New item has been set.\n";
			break;
		}
		current = current->link;
	}

	if (itemFound == false)
	{
		cout << "Cannot set value due to item not found.\n";
	}
}

void RowNode::deleteItemFirst()
{
	if (size > 0)
	{
		ColumnNode* toBeDeleted = head;
		head = head->link;
		delete toBeDeleted;
		size--;
	}
	else
	{
		cout << "There is nothing to be deleted.";
	}
}

void RowNode::deleteItemLast()
{
	if (size > 0)
	{
		// if the list only has one item
		if (size == 1)
		{
			delete head;
			head = NULL;
		}
		else
		{
			ColumnNode* beforeLast = head;
			while (beforeLast->link->link != NULL)
			{
				beforeLast = beforeLast->link;
			}
			delete beforeLast->link;
			beforeLast->link = NULL;
		}
		size--;
	}
	else
	{
		cout << "There is nothing to be deleted.";
	}
}

void RowNode::deleteItemAt(int index)
{
	if (index < size)
	{
		ColumnNode* prev = NULL;
		ColumnNode* toDelete = head;
		for (int i = 0; i < index; i++)
		{
			prev = toDelete;
			toDelete = toDelete->link;
		}
		prev->link = toDelete->link;
		delete toDelete;
		size--;
	}
	else
	{
		cout << "The item index to be deleted is out of bounds.";
	}
}


class UTM
{
public:
	int matrixSize;

	// LinkedList properties
	RowNode* head;
	int size;

	// LinkedList functions
	void insertRowAtBeginning(int rowIndex);

	void insertRowAtEnd(int rowIndex);

	void insertRowAt(int rowIndex);

	bool searchRow(int rowIndex);

	RowNode* getRowAt(int rowIndex);

	void deleteRowFirst();

	void deleteRowLast();

	void deleteRowAt(int index);

	UTM(int matrixSize);

	~UTM();

	void inputElements(int rowIndex, int columnIndex, int value);

	void displayMatrix();

	UTM* sumUTM(UTM &other);
};

void UTM::insertRowAtBeginning(int rowIndex)
{
	RowNode* newNode = new RowNode;
	newNode->rowIndex = rowIndex;
	newNode->link = head;
	head = newNode;
	size++;
}

void UTM::insertRowAtEnd(int rowIndex)
{
	RowNode* newNode = new RowNode;
	newNode->rowIndex = rowIndex;
	newNode->link = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		RowNode* last = head;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = newNode;
	}
	this->size++;
}

void UTM::insertRowAt(int rowIndex)
{
	RowNode* newNode = new RowNode;
	newNode->rowIndex = rowIndex;
	RowNode* prev = head;

	bool placedInBetween = false;

	for (int i = 0; i < size; i++)
	{
		if (prev->rowIndex > rowIndex)
		{
			placedInBetween = true;
			break;
		}
		prev = prev->link;
	}

	if (placedInBetween == true)
	{
		newNode->link = prev->link;
		prev->link = newNode;
		size++;
	}
	else
	{
		insertRowAtEnd(rowIndex);
	}
}

bool UTM::searchRow(int rowIndex)
{
	RowNode* current = head;
	while (current != NULL)
	{
		if (current->rowIndex == rowIndex)
		{
			return true;
		}
		else
		{
			current = current->link;
		}
	}
	return false;
}

RowNode* UTM::getRowAt(int rowIndex)
{
	if (rowIndex < 0)
	{
		cout << "Cannot use negative index.\n";
	}
	RowNode* current = head;

	bool itemFound = false;

	for (int i = 0; i < size; i++)
	{
		if (current->rowIndex == rowIndex)
		{
			itemFound = true;
			return current;
		}
		current = current->link;
	}

	// if after iterating item not found
	if (itemFound == false)
	{
		return NULL;
	}
}

void UTM::deleteRowFirst()
{
	if (size > 0)
	{
		RowNode* toBeDeleted = head;
		head = head->link;
		delete toBeDeleted;
		size--;
	}
	else
	{
		cout << "There is nothing to be deleted.";
	}
}

void UTM::deleteRowLast()
{
	if (size > 0)
	{
		// if the list only has one item
		if (size == 1)
		{
			delete head;
			head = NULL;
		}
		else
		{
			RowNode* beforeLast = head;
			while (beforeLast->link->link != NULL)
			{
				beforeLast = beforeLast->link;
			}
			delete beforeLast->link;
			beforeLast->link = NULL;
		}
		size--;
	}
	else
	{
		cout << "There is nothing to be deleted.";
	}
}

void UTM::deleteRowAt(int index)
{
	if (index < size)
	{
		RowNode* prev = NULL;
		RowNode* toDelete = head;
		for (int i = 0; i < index; i++)
		{
			prev = toDelete;
			toDelete = toDelete->link;
		}
		prev->link = toDelete->link;
		delete toDelete;
		size--;
	}
	else
	{
		cout << "The row index to be deleted is out of bounds.";
	}
}

UTM::UTM(int matrixSize)
{
	this->matrixSize = matrixSize;
	this->size = 0;
	this->head = NULL;
}

void UTM::inputElements(int rowIndex, int columnIndex, int value)
{
	// determine the start index of the Upper Triangular Matrix (UTM)
	int startIndex = 0;

	// if the rowIndex is bigger or equal to the matrixSize, reject input
	if (rowIndex >= matrixSize || columnIndex < rowIndex || columnIndex >= matrixSize)
	{
		cout << "Cannot put " << value << " to row number " << rowIndex << " and column number " << columnIndex << ". " << endl << endl;
	}
	else
	{
		// if row does not exists, create a new row after validating the rowIndex and columnIndex provided
		if ((searchRow(rowIndex) == false || this->size == 0))
		{
			// if index == 0 or LinkedList size is 0, create new row at the beginning of the LinkedList
			if (rowIndex == 0 || size == 0)
			{
				insertRowAtBeginning(rowIndex);
			}

			// else, insert at the exact row
			else {
				insertRowAt(rowIndex);
			}
		}

		// if row does exists, search for column
		RowNode* row = getRowAt(rowIndex);

		// set the start index
		startIndex = row->rowIndex;

		// if column does not exist, create new ColumnNode
		if (row->searchItem(columnIndex) == false || row->size == 0)
		{
			// insert the element to the ColumnNode if the value is other than 0
			if (value != 0)
			{
				// if index == 0 or LinkedList size is 0, create new column at the beginning of the LinkedList
				if (columnIndex == 0 || size == 0)
				{
					row->insertAtBeginning(value, columnIndex);
				}
				// else, insert at the exact column
				else
				{
					row->insertItemAt(value, columnIndex);
				}
				cout << "Done setting " << value << " to row number " << rowIndex << " and column number " << columnIndex << "." << endl;
			}
		}
		// else the ColumnNode exists, change the value
		else
		{
			// if the changed value is 0, delete the ColumnNode
			if (value == 0)
			{
				// if the ColumnNode is the head of the RowNode, delete the first item of the RowNode
				if (row->getColumnAt(columnIndex) == row->head)
				{
					row->deleteItemFirst();
				}
				// else if the ColumnNode has no element to link, delete the last item of the RowNode
				else if (row->getColumnAt(columnIndex)->link == NULL)
				{
					row->deleteItemLast();
				}
				// else, the ColumnNode is in between other ColumnNode
				else
				{
					row->deleteItemAt(columnIndex);
				}

				// check if after deletion the RowNode is empty, delete the RowNode
				if (row->size == 0)
				{
					// if the RowNode is the head of the UTM, delete the first item of the UTM
					if (row == head)
					{
						deleteRowFirst();
					}
					// else if the RowNode has no element to link, delete the last item of the UTM
					else if (row->link == NULL)
					{
						deleteRowLast();
					}
					// else, the RowNode is in between other RowNode
					else
					{
						deleteRowAt(rowIndex);
					}
				}
			}
			// else, the changed value is other than 0, set the ColumnNode value to the new specified value
			else
			{
				row->setItemAt(value, columnIndex);
			}
			cout << "Done setting " << value << " to row number " << rowIndex << " and column number " << columnIndex << "." << endl;
		}
	}
}

void UTM::displayMatrix()
{
	// iterate each LinkedList to print each ColumnNode
	for (int i = 0; i < this->matrixSize; i++)
	{
		// search for the RowNode
		if (searchRow(i) == true)
		{
			RowNode* row = getRowAt(i);
			// search for the ColumnNode to print
			for (int j = 0; j < matrixSize; j++)
			{
				// print the value of the ColumnNode
				cout << row->getItemAt(j) << "\t";
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < this->matrixSize; j++)
			{
				cout << 0 << "\t";
			}
			cout << endl;
		}
	}
	cout << "\n";
}

UTM * UTM::sumUTM(UTM &other)
{
	// create new UTM object as result to be returned
	UTM* resultMatrix = new UTM(matrixSize);

	// do matrix addition to each of the matrix element
	for (int i = 0; i < matrixSize; i++)
	{
		RowNode* elementOneRow = getRowAt(i);
		RowNode* elementTwoRow = other.getRowAt(i);

		// traverse through the column
		for (int j = 0; j < matrixSize; j++)
		{
			int elementOneValue = 0;
			int elementTwoValue = 0;
			int elementResult = 0;

			// if row found, search for the columnNode
			if (elementOneRow != NULL)
			{
				elementOneValue = elementOneRow->getItemAt(j);
			}

			if (elementTwoRow != NULL)
			{
				elementTwoValue = elementTwoRow->getItemAt(j);
			}

			elementResult = elementOneValue + elementTwoValue;

			// if the result is other than 0, write the value to the resultMatrix
			if (elementResult != 0)
			{
				resultMatrix->inputElements(i, j, elementResult);
			}
		}
	}

	return resultMatrix;
}

UTM::~UTM()
{
	// delete the ColumnNode first
	// after deleting the columnNode, proceed with deleting RowNode
	RowNode* current = head;
	while (head != NULL)
	{
		current->~RowNode();
		current = current->link;
		delete head;
		head = current;
	}
}

int main()
{
	int matrixSize;
	int userOperation;
	int matrixOperation;

	// Intro section
	do {
		cout << "Welcome to the Upper Triangular Matrix (UTM) operator!" << endl;
		cout << "How big is the size of your UTM? ";
		cin >> matrixSize;

		if (matrixSize <= 0)
		{
			cout << "You should provide a positive matrix size." << endl;
		}

	} while (matrixSize <= 0);

	// instantiate the UTM object
	UTM matrixOne(matrixSize);
	UTM matrixTwo(matrixSize);
	UTM* resultMatrix;
	
	// Main program flow
	cout << "Two matrices with the size of " << matrixSize << " have been created." << endl;
	do
	{
		cout << "Here are the operations that you can choose: " << endl;
		cout << "1. Modify Matrix One" << endl;
		cout << "2. Modify Matrix Two" << endl;
		cout << "3. Sum Matrix One and Matrix Two" << endl;
		cout << "4. Exit" << endl;
		cout << "What do you want to do? ";
		cin >> userOperation;

		switch (userOperation)
		{
		// user choose "Modify Matrix One"
		case 1:
			do {
				cout << "Here are the matrix operations that you can choose for Matrix One:" << endl;
				cout << "1. Input elements" << endl;
				cout << "2. Display matrix" << endl;
				cout << "3. Clear matrix" << endl;
				cout << "4. Back to previous menu" << endl;
				cout << "What do you want to do? ";
				cin >> matrixOperation;

				switch (matrixOperation)
				{
				// user choose "Input elements"
				case 1:
					int rowIndex;
					int columnIndex;
					int value;

					cout << "In which row does your element a member of? ";
					cin >> rowIndex;
					cout << "In which column does your element exists? ";
					cin >> columnIndex;
					cout << "What is the value you want to store for the element? ";
					cin >> value;

					// use user input to change the matrix value
					matrixOne.inputElements(rowIndex, columnIndex, value);
					break;

				// user choose "Display matrix"
				case 2:
					matrixOne.displayMatrix();
					break;

				// user choose "Clear matrix"
				case 3:
					matrixOne.~UTM();
					matrixOne.matrixSize = matrixSize;
					matrixOne.size = 0;
					matrixOne.head = NULL;
					cout << "Matrix One has been cleared." << endl;
					break;

				// user choose "Back to previous menu"
				case 4:
					cout << "Returning to the previous menu." << endl;
					break;

				// user choose invalid option
				default:
					cout << "Please provide a proper matrix operation option number." << endl;
					break;
				}
			} while (matrixOperation != 4);

			break;

		// user choose "Modify Matrix Two"
		case 2:
			do {
				cout << "Here are the matrix operations that you can choose for Matrix Two:" << endl;
				cout << "1. Input elements" << endl;
				cout << "2. Display matrix" << endl;
				cout << "3. Clear matrix" << endl;
				cout << "4. Back to previous menu" << endl;
				cout << "What do you want to do? ";
				cin >> matrixOperation;

				switch (matrixOperation)
				{
				// user choose "Input elements"
				case 1:
					int rowIndex;
					int columnIndex;
					int value;

					cout << "In which row does your element a member of? ";
					cin >> rowIndex;
					cout << "In which column does your element exists? ";
					cin >> columnIndex;
					cout << "What is the value you want to store for the element? ";
					cin >> value;

					// use user input to change the matrix value
					matrixTwo.inputElements(rowIndex, columnIndex, value);
					break;

				// user choose "Display matrix"
				case 2:
					matrixTwo.displayMatrix();
					break;

				// user choose "Clear matrix"
				case 3:
					matrixTwo.~UTM();
					matrixTwo.matrixSize = matrixSize;
					matrixTwo.size = 0;
					matrixTwo.head = NULL;
					cout << "Matrix Two has been cleared." << endl;
					break;

				// user choose "Back to previous menu"
				case 4:
					cout << "Returning to the previous menu." << endl;
					break;

				// user choose invalid option
				default:
					cout << "Please provide a proper matrix operation option number." << endl;
					break;
				}
			} while (matrixOperation != 4);

			break;

		// user choose "Sum Matrix One and Matrix Two"
		case 3:
			// calculate and print the sum of Matrix One and Matrix Two
			resultMatrix = matrixOne.sumUTM(matrixTwo);
			cout << "Here is the result of adding Matrix One with Matrix Two." << endl;
			resultMatrix->displayMatrix();
			break;

		// user choose "Exit"
		case 4:
			// free the memory from values stored inside the Matrix object and print goodbye message
			matrixOne.~UTM();
			matrixTwo.~UTM();
			cout << "Thank you for using the Upper Triangular Matrix (UTM) program!" << endl;
			cout << "Have a nice day, and see you next time!" << endl;
			break;

		// user choose invalid option
		default:
			cout << "Please provide a proper option number." << endl;
			break;
		}
	} while (userOperation != 4);

	system("pause");
}

