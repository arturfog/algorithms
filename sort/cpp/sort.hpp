class Sort {
public:
  virtual bool sort() = 0;
};

class SelectionSort : public Sort {
  bool sort();
};

class InsertionSort : public Sort {
  bool sort();
};

class MergeSort : public Sort {
private:
  unsigned int merge();  
};

class QuickSort : public Sort {
private:
  unsigned int partition();
};
