#include <string>
using std::string;

namespace stefani_containers{

	class MyVector
	{
	private:
		int size_;
		double* elements_;
		void check_elements() const;

	public:
		MyVector(int size);
		~MyVector();

		class Invalid {

		private: string message_;
		public:
			Invalid(string message);
			string GetMessage(void);
		};

		double& operator[](int);
		double operator[](int) const;

		void safe_set(int, double);
		double safe_get(int) const;

	};

}


