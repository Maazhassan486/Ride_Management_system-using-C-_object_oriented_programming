
# Ride Management System (TMS)

**Project By:** Maaz Hassan  
**Project Title:** Ride Management System Using OOP

---

## Overview

The Ride Management System (TMS) is a C++ application designed to manage various aspects of ride and delivery services. This system demonstrates advanced object-oriented programming concepts by utilizing multiple classes to model real-world entities. It provides functionality to:

- Manage customers and their booking history.
- Handle driver records, including license details, experience, and service history.
- Manage vehicles and their associated features, registration details, and maintenance information.
- Schedule and track services (such as rides and deliveries).
- Perform operations like adding new customers, drivers, vehicles, as well as removing or updating existing records.

---

## Features

- **Customer Management:**  
  - Add new customers with their personal details.
  - Maintain a booking history for each customer.

- **Driver Management:**  
  - Add new drivers with details like age, experience, salary, and license information.
  - Remove drivers by their unique IDs.
  - Manage driver service history and ranking.

- **Vehicle Management:**  
  - Add and remove vehicles with details including registration number, average mileage, license type, fuel type, manufacturing date, and feature list.
  - Manage service history for vehicles.

- **Service Scheduling:**  
  - Book rides or deliveries with details such as source, destination, distance, booking date/time, and status.
  - Track service progress and update status (pending, completed, or cancelled).

- **Additional Utilities:**  
  - Generate lists of customers, drivers, and vehicle data.
  - Update or remove service requests.

---

## Project Structure

The system is built using multiple classes that encapsulate the core functionality:

- **Name, Date, mTime:**  
  Basic classes to handle personal names, dates, and time respectively.

- **Service:**  
  Models a generic service request, containing details like source, destination, booking date/time, fuel rate, and associated customer/driver/vehicle IDs.

- **Ride and Delivery:**  
  Derived from the Service class, these classes handle ride-specific and delivery-specific details.

- **Person, Customer, and Driver:**  
  - **Person:** Base class for individuals.
  - **Customer:** Inherits from Person and includes booking history.
  - **Driver:** Inherits from Person and includes license details, experience, salary, overall ranking, and service history.

- **Feature and Vehicle:**  
  - **Feature:** Represents specific features of a vehicle (e.g., cost, description).
  - **Vehicle:** Contains information about the vehicle such as registration, mileage, fuel type, manufacturing date, and an array of Features.

- **TMS (Ride Management System):**  
  The central class that aggregates customers, drivers, and vehicles. It provides functions to add, remove, and list data, as well as handle service requests.

---

## Prerequisites

- **C++ Compiler:** Ensure you have a C++ compiler installed (e.g., g++, clang, or Visual Studio).
- **Standard C++ Libraries:** The project uses standard C++ libraries, so no additional third-party libraries are required.

---

## Compilation & Execution

### Using g++ (on Linux/Mac or Git Bash on Windows)

1. **Open a terminal and navigate to the project directory:**
   ```bash
   cd /path/to/your/project-directory
   ```

2. **Compile the project:**
   ```bash
   g++ -std=c++11 -o TMS main.cpp
   ```
   Replace `main.cpp` with the appropriate file(s) if your project consists of multiple source files. You may need to include additional source files:
   ```bash
   g++ -std=c++11 main.cpp Name.cpp Date.cpp mTime.cpp Service.cpp Ride.cpp Delivery.cpp Person.cpp Customer.cpp Driver.cpp Feature.cpp Vehicle.cpp TMS.cpp -o TMS
   ```

3. **Run the executable:**
   ```bash
   ./TMS
   ```

### Using an IDE (e.g., Visual Studio, Code::Blocks, or CLion)

1. Create a new C++ project.
2. Add all the source and header files to your project.
3. Configure your project to use C++11 (or later).
4. Build and run the project through the IDE.

---

## Usage Instructions

Once compiled and executed, the system presents a menu with various options such as:
- Creating a new customer.
- Adding a new driver.
- Removing a driver.
- Adding or removing vehicles.
- Viewing lists of customers and drivers.
- Managing service requests (booking, cancelling, completing).

Follow the on-screen prompts to interact with the system.

---

## Important Considerations

- **Data Persistence:**  
  This system writes data to text files (e.g., `Customer_List.txt`, `Driver_List.txt`) for record-keeping. Ensure that the application has the necessary file permissions.

- **Memory Management:**  
  The project makes use of dynamic memory allocation. Be cautious of potential memory leaks. Review the destructors provided in each class.

- **Error Handling:**  
  Basic error handling is implemented. Further robustness may be added as needed.

- **Experimentation:**  
  This project is part of an academic experiment in applied artificial intelligence. The design and implementation reflect learning outcomes in OOP, data handling, and system design.

---

## Contributing

Contributions and improvements are welcome! If you find issues or want to add features, feel free to fork the repository, make your changes, and submit a pull request.

---

## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for more information.
