#include <iostream>
#include <cstring>
#include <climits>
#include <stdexcept>

#include "../include/GymSystem.h"
#include "../include/Member.h"
#include "../include/Trainer.h"
#include "../include/GroupSession.h"
#include "../include/PrivateSession.h"
#include "../include/weights.h"
#include "../include/machines.h"
#include "../include/weightMachine.h"
#include "../include/MonthlySubscription.h"
#include "../include/AnnualSubscription.h"

static const int MAX_INPUT_LEN = 256;

static int readInt(const char* prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(INT_MAX, '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid number, please try again." << std::endl;
    }
}

static int readIntInRange(const char* prompt, int minVal, int maxVal) {
    while (true) {
        int v = readInt(prompt);
        if (v >= minVal && v <= maxVal) return v;
        std::cout << "Value must be between " << minVal << " and " << maxVal << "." << std::endl;
    }
}

static double readPositiveDouble(const char* prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0) {
            std::cin.ignore(INT_MAX, '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid value, please enter a non-negative number." << std::endl;
    }
}

static void readLine(const char* prompt, char* buffer, int bufferSize) {
    std::cout << prompt;
    std::cin.getline(buffer, bufferSize);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        buffer[0] = '\0';
    }
}

static bool readYesNo(const char* prompt) {
    char buffer[8];
    while (true) {
        readLine(prompt, buffer, 8);
        if (buffer[0] == 'y' || buffer[0] == 'Y') return true;
        if (buffer[0] == 'n' || buffer[0] == 'N') return false;
        std::cout << "Please answer with y or n." << std::endl;
    }
}

static void registerTrainer(GymSystem& gym) {
    std::cout << "\n--- Register New Trainer ---" << std::endl;

    char name[MAX_INPUT_LEN];
    readLine("Enter trainer name: ", name, MAX_INPUT_LEN);
    int id = readInt("Enter ID number: ");
    char phone[MAX_INPUT_LEN];
    readLine("Enter phone: ", phone, MAX_INPUT_LEN);
    char address[MAX_INPUT_LEN];
    readLine("Enter address: ", address, MAX_INPUT_LEN);
    char specialty[MAX_INPUT_LEN];
    readLine("Enter specialty: ", specialty, MAX_INPUT_LEN);
    
    int exp = readIntInRange("Years of experience: ", 0, 60);
    double salary = readPositiveDouble("Monthly salary: ");

    Trainer* trainer = new Trainer(name, id, phone, address, specialty, exp, salary);
    try {
        gym.addTrainer(trainer);
        std::cout << "Trainer registered successfully." << std::endl;
    } catch (...) {
        delete trainer;
        throw;
    }
}

static void registerMember(GymSystem& gym) {
    std::cout << "\n--- Register New Member ---" << std::endl;

    char name[MAX_INPUT_LEN];
    readLine("Enter member name: ", name, MAX_INPUT_LEN);
    int id = readInt("Enter ID number: ");
    char phone[MAX_INPUT_LEN];
    readLine("Enter phone: ", phone, MAX_INPUT_LEN);
    char address[MAX_INPUT_LEN];
    readLine("Enter address: ", address, MAX_INPUT_LEN);
    char joinDate[MAX_INPUT_LEN];
    readLine("Enter join date (dd/mm/yyyy): ", joinDate, MAX_INPUT_LEN);

    std::cout << "Choose Subscription Type:" << std::endl
              << "  1. Monthly Subscription" << std::endl
              << "  2. Annual Subscription" << std::endl;
    int subType = readIntInRange("Choice: ", 1, 2);

    Subscription* sub = nullptr;
    if (subType == 1) {
        int months = readIntInRange("Duration (months): ", 1, 12);
        sub = new MonthlySubscription(250.0, months);
    } else {
        double discount = readPositiveDouble("Discount percentage: ");
        sub = new AnnualSubscription(200.0, discount);
    }

    Member* member = new Member(name, id, phone, address, joinDate, sub);

    try {
        gym.addMember(member);
        std::cout << "Member registered successfully." << std::endl;
    } catch (...) {
        delete member;
        delete sub;
        throw;
    }
}

static void addEquipment(GymSystem& gym) {
    std::cout << "\n--- Add Gym Equipment ---" << std::endl;
    std::cout << "Choose equipment category:" << std::endl
              << "  1. Free Weights" << std::endl
              << "  2. Cable Machine" << std::endl
              << "  3. Integrated Weight Machine" << std::endl;
    int type = readIntInRange("Category: ", 1, 3);

    char name[MAX_INPUT_LEN];
    readLine("Enter equipment name: ", name, MAX_INPUT_LEN);
    char muscle[MAX_INPUT_LEN];
    readLine("Target muscle group: ", muscle, MAX_INPUT_LEN);

    Equipment* eq = nullptr;
    if (type == 1) {
        double weight = readPositiveDouble("Weight (KG): ");
        eq = new weights(name, muscle, true, weight);
    } else if (type == 2) {
        char cable[MAX_INPUT_LEN];
        readLine("Cable type: ", cable, MAX_INPUT_LEN);
        eq = new machines(name, muscle, true, cable);
    } else {
        double weight = readPositiveDouble("Weight (KG): ");
        char cable[MAX_INPUT_LEN];
        readLine("Cable type: ", cable, MAX_INPUT_LEN);
        int pulleys = readIntInRange("Pulley count: ", 1, 10);
        eq = new weightMachine(name, muscle, true, weight, cable, pulleys);
    }

    try {
        gym.addEquipment(eq);
        std::cout << "Equipment registered successfully." << std::endl;
    } catch (...) {
        delete eq;
        throw;
    }
}

static void createClassSession(GymSystem& gym) {
    std::cout << "\n--- Create Class Session ---" << std::endl;

    if (gym.getNumTrainers() == 0) {
        std::cout << "System Error: No trainers available in the system. Please register a trainer first." << std::endl;
        return;
    }

    gym.printTrainers();
    int trainerIdx = readIntInRange("Choose trainer index for this session: ", 0, gym.getNumTrainers() - 1);
    Trainer* selectedTrainer = gym.getTrainerByIndex(trainerIdx);

    std::cout << "Choose session type:" << std::endl
              << "  1. Group Session" << std::endl
              << "  2. Private Session" << std::endl;
    int type = readIntInRange("Type: ", 1, 2);

    char className[MAX_INPUT_LEN];
    readLine("Enter class name: ", className, MAX_INPUT_LEN);

    ClassSession* session = nullptr;
    if (type == 1) {
        int maxParticipants = readIntInRange("Max participants capacity: ", 5, 50);
        session = new GroupSession(className, *selectedTrainer, maxParticipants);
    } else {
        char focus[MAX_INPUT_LEN];
        readLine("Focus area: ", focus, MAX_INPUT_LEN);
        bool rehab = readYesNo("Is this a rehabilitation session? (y/n): ");
        session = new PrivateSession(className, *selectedTrainer, focus, rehab);
    }

    try {
        gym.addClass(session);
        std::cout << "Session created successfully." << std::endl;
    } catch (...) {
        delete session;
        throw;
    }
}

static void memberPaymentOperation(GymSystem& gym) {
    std::cout << "\n--- Process Member Payment ---" << std::endl;

    if (gym.getNumMembers() == 0) {
        std::cout << "System Error: No members available in the system. Please register a member first." << std::endl;
        return;
    }

    gym.printMembers();
    int memberIdx = readIntInRange("Choose member index: ", 0, gym.getNumMembers() - 1);
    Member* selectedMember = gym.getMemberByIndex(memberIdx);

    selectedMember->pay();
    std::cout << "Payment processed successfully." << std::endl;
}

static void manageWorkoutPlan(GymSystem& gym) {
    std::cout << "\n--- Manage Workout Plan ---" << std::endl;
    
    if (gym.getNumTrainers() == 0 || gym.getNumMembers() == 0) {
        std::cout << "System Error: Need both a trainer and a member in the system." << std::endl;
        return;
    }

    gym.printTrainers();
    int trainerIdx = readIntInRange("Choose trainer index: ", 0, gym.getNumTrainers() - 1);
    Trainer* trainer = gym.getTrainerByIndex(trainerIdx);

    gym.printMembers();
    int memberIdx = readIntInRange("Choose member index: ", 0, gym.getNumMembers() - 1);
    Member* member = gym.getMemberByIndex(memberIdx);

    trainer->createWorkoutPlan(member);
    std::cout << "Workout plan assigned and updated successfully." << std::endl;
}

static void registerMemberToClass(GymSystem& gym) {
    std::cout << "\n--- Register Member to Session ---" << std::endl;
    
    if (gym.getNumMembers() == 0) {
        std::cout << "System Error: No members available." << std::endl;
        return;
    }

    gym.printMembers();
    int memberIdx = readIntInRange("Choose member index: ", 0, gym.getNumMembers() - 1);
    Member* member = gym.getMemberByIndex(memberIdx);

    gym.inviteMemberToSession(member);
    std::cout << "Member registration to class processed." << std::endl;
}

static void removeMemberOperation(GymSystem& gym) {
    std::cout << "\n--- Remove Member From System ---" << std::endl;

    if (gym.getNumMembers() == 0) {
        std::cout << "System Error: No members available to remove." << std::endl;
        return;
    }

    gym.printMembers();
    int id = readInt("Enter ID of member to remove: ");
    
    gym.deleteMember(id);
    std::cout << "Member removal process executed." << std::endl;
}

static void printMenu() {
    std::cout << "\n========== Gym Management System ==========" << std::endl
              << "  1.  Register new Trainer" << std::endl
              << "  2.  Register new Member & Subscription" << std::endl
              << "  3.  Add Gym Equipment" << std::endl
              << "  4.  Create Class Session" << std::endl
              << "  5.  Process Member Payment" << std::endl
              << "  6.  Manage Workout Plan (Trainer)" << std::endl
              << "  7.  Register Member to Session" << std::endl
              << "  8.  Remove Member From System" << std::endl
              << "  9.  Print Gym System General Report" << std::endl
              << "  0.  Exit" << std::endl
              << "===========================================" << std::endl;
}

int main() {
    GymSystem gym;
    int choice;

    std::cout << "Welcome to the GymSystem Management Platform!" << std::endl;

    do {
        printMenu();
        choice = readInt("Choose an option: ");

        try {
            switch (choice) {
                case 1: registerTrainer(gym);       break;
                case 2: registerMember(gym);        break;
                case 3: addEquipment(gym);          break;
                case 4: createClassSession(gym);    break;
                case 5: memberPaymentOperation(gym);break;
                case 6: manageWorkoutPlan(gym);     break;
                case 7: registerMemberToClass(gym); break;
                case 8: removeMemberOperation(gym); break;
                case 9: 
                    std::cout << "\n--- Generating System Reports ---" << std::endl;
                    gym.printReports(); 
                    break;
                case 0: 
                    std::cout << "Exiting system. Goodbye!" << std::endl; 
                    break;
                default:
                    std::cout << "Invalid choice. Please pick 0-9." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Runtime Error: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "An unexpected critical error occurred." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
