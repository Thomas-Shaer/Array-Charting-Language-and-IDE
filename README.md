# Array Programming Language & IDE for Charting Data

![](Screenshots/multiide.PNG)

This project aims to create an all-in-one software for programmatically creating charts via a custom-built programming language, designed specifically to provide an alternative to Excels chart building features. The programming language is an array language, a paradigm where computations apply to entire arrays at once, often in parallel, which is necessary for charting since chart data is in the form of data series that can be interpreted as an array. 

The software is delivered in the form of an IDE (Integrated Development Environment), which allows the user to write and test code. Although the software utilises a programming language, one of the primary aims of the project is to keep the language as beginner-friendly as possible such that it is accessible to non-technical users. Additionally, since the project is aiming to act as a replacement for Excels chart building features, another important aspect is compatibility with Excel. To act as an effective replacement, it is essential that the user can import and export data to and from Excel.

## Install (full version in Setup.pdf)

### Executable
I’ve also packaged a binary (.exe) version of the software in this zip called “Executable”. If you want to run the software without compiling it, you can simply extract this folder from the zip, and execute “Thomas_Shaer_Dissertation.exe”. You can also run the tests by executing “Tests.exe”. I also give a sample code file called "tradingdemo.al" in the Example Code directory. This is the same example seen in the main report under “backtesting case study”. I have also included the EURUSD.csv data that is required for this script in the Example Data directory.

### Setup
#### Requirements

 - Visual Studio 2019 v.16.8.4
 - Microsoft .NET framework v.4.8.04161
 - Windows 10/11


The software is setup to run on 32bit machines therefore any Windows 10/11 OS should support it. The project may work with slightly different versions of Visual Studio and .NET framework but above is what it was created with.

#### Steps (main software)

 1. Double click the “CodeBase.sln” file.
 2. This will open the project in Visual Studio 2019. Locate and open the “Solution Explorer” tab if not already present. You should see two projects: CodeBase and Tests.
 3. The CodeBase project contains the actual code for the software, while the Tests project contains the code for testing the software.
 4. It is recommended that you first run the CodeBase project as Tests is dependent on it.
 5. The GUI should open automatically. Note, if the windows look funny, they can be resized and opened from the main tool bar.

#### Steps (tests)
1. To run the tests, you should open the “Test Explorer” window.
2. By default, no tests might be detected. Press the green button on the top left of the text explorer window, which will find and run all the tests automatically. The Tests code will be recompiled the first time you run it (seen in the output window), so it might take a few minutes to run.

#### Additional Compiler Information

 - Windows SDK version: 10.0
 - Platform Toolset: Visual Studio 2019 (v142)
 - C++ Language Standard: Previous from the Latest C++ Working Draft (/std:c++latest)
