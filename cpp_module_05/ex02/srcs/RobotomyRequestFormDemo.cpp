/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormDemo.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:20:00 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 15:53:04 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

void testRobotomyRequestFormWithDifferentGrades() {
    printColored("\n=== TESTING ROBOTOMY REQUEST FORM WITH VARIOUS GRADES ===", colorBlue);
    
    RobotomyRequestForm robotomyForm("Target01");
    
    // Test with various bureaucrat grades
    Bureaucrat ceo("CEO", 1);             // Highest possible grade
    Bureaucrat director("Director", 45);   // Can execute (exec grade is 45)
    Bureaucrat manager("Manager", 46);     // Cannot execute (too low) but can sign
    Bureaucrat clerk("Clerk", 72);         // Can sign (sign grade is 72)
    Bureaucrat intern("Intern", 73);       // Cannot sign (too low)
    
    printColored("Form status before any action:", colorGreen);
    std::cout << robotomyForm << std::endl;
    
    // Test signing with different grades
    printColored("\nTesting form signing with different bureaucrats:", colorGreen);
    try {
        intern.signForm(robotomyForm);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Clerk should be able to sign
    clerk.signForm(robotomyForm);
    std::cout << "After clerk tried to sign: " << robotomyForm << std::endl;
    
    // Test execution with different grades
    printColored("\nTesting form execution with different bureaucrats:", colorGreen);
    
    // Attempt execution with unsigned form (we already signed it above)
    printColored("\nAttempting execution with various grades:", colorPurple);
    
    executeTryCatch(robotomyForm, intern);      // Too low grade
    executeTryCatch(robotomyForm, manager);     // Just 1 below required
    
    // Testing multiple robotomy attempts to demonstrate randomness
    printColored("\nTesting multiple robotomy attempts (50% success rate):", colorBlue);
    for (int i = 0; i < 5; i++) {
        std::cout << "Attempt " << i+1 << ": ";
        executeTryCatch(robotomyForm, director);
    }
    
    printColored("Testing with highest grade bureaucrat:", colorGreen);
    executeTryCatch(robotomyForm, ceo);
}

void testRobotomyBorderlineCases() {
    printColored("\n=== TESTING ROBOTOMY BORDERLINE CASES ===", colorBlue);
    
    // Create form with default target
    RobotomyRequestForm defaultForm;
    std::cout << "Default form target: Standard Robot" << std::endl;
    
    // Test with exactly required grades
    Bureaucrat exactSigner("ExactSigner", 72);   // Exactly the signing grade
    Bureaucrat exactExecutor("ExactExecutor", 45); // Exactly the execution grade
    
    printColored("\nTesting with exact required grades:", colorGreen);
    exactSigner.signForm(defaultForm);
    std::cout << "Form after signing with exact grade: " << defaultForm << std::endl;
    
    printColored("Executing with exact grade:", colorBlue);
    exactExecutor.executeForm(defaultForm);
    
    // Test multiple sign attempts
    printColored("\nTesting multiple signing attempts:", colorGreen);
    std::cout << "Before second signing attempt: " << defaultForm << std::endl;
    exactSigner.signForm(defaultForm); // Try to sign again
    std::cout << "After second signing attempt: " << defaultForm << std::endl;
}

void testRobotomyExceptionHandling() {
    printColored("\n=== TESTING ROBOTOMY EXCEPTION HANDLING ===", colorRed);
    
    RobotomyRequestForm robotomyForm("Subject");
    
    // Test form before signing
    printColored("\nAttempting to execute unsigned form:", colorGreen);
    try {
        Bureaucrat director("Director", 45);
        robotomyForm.execute(director);
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    // Test with signing but insufficient execution grade
    printColored("\nSigning form but executing with insufficient grade:", colorGreen);
    try {
        Bureaucrat manager("Manager", 60);
        Bureaucrat assistant("Assistant", 80);
        
        manager.signForm(robotomyForm);
        std::cout << "Form signed successfully: " << robotomyForm << std::endl;
        
        robotomyForm.execute(assistant);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void robotomyDemo() {
    waitForEnter("Ready to test Robotomy Request Form with different grades.");
    testRobotomyRequestFormWithDifferentGrades();

    waitForEnter("Ready to test borderline cases for Robotomy.");
    testRobotomyBorderlineCases();

    waitForEnter("Ready to test exception handling for Robotomy.");
    testRobotomyExceptionHandling();
}
