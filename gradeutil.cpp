/*gradeutil.cpp*/

//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #02: GradeUtil API
// 

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gradeutil.h"

using namespace std;


//
// API:
//

// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline)
{

  //
  // TODO:
  // 
     string Dept,Title,Instructor, Number, Section, NumA, NumB, NumC, NumD, NumF, NumI, NumNR, NumS, NumU, NumW;
    
    stringstream ss(csvline);
    
    getline(ss, Dept, ',');
    
    getline(ss, Number, ',');
    
    getline(ss, Section, ',');
    
    getline(ss, Title, ',');
    
    getline(ss, NumA, ',');
    
    getline(ss, NumB, ',');
    
    getline(ss, NumC, ',');
    
    getline(ss, NumD, ',');
    
    getline(ss, NumF, ',');
    
    getline(ss, NumI, ',');
    
    getline(ss, NumNR, ',');
    
    getline(ss, NumS, ',');
    
    getline(ss, NumU, ',');
    
    getline(ss, NumW, ',');
    
    getline(ss, Instructor);
    
    Course C(Dept, Title, stoi(Number), stoi(Section), Instructor, stoi(NumA), stoi(NumB), stoi(NumC), 
             stoi(NumD), stoi(NumF), stoi(NumI), stoi(NumS), stoi(NumU), stoi(NumW), stoi(NumNR));
    
  return C;
}


//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  
  //
  // TODO:
  //
 
   if (c.getGradingType() == Course::Letter){
       DFW = c.NumD+c.NumF+c.NumW;
          N = c.NumA+c.NumB+c.NumC+c.NumD+c.NumF+c.NumW; 
        return ((double)DFW/(double)N)*100.0;
   }
    return 0.0;
}

double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  
  //
  // TODO:
  //
  //double result=0.0;
    for(auto &c : dept.Courses) {
        if (c.getGradingType() == Course::Letter){
        DFW = DFW+c.NumD+c.NumF+c.NumW;
        N = N+c.NumA+c.NumB+c.NumC+c.NumD+c.NumF+c.NumW; 
        }
    }
  if(N==0){
      return 0.0;
  }
  return (double (DFW)/double (N))*100.0;
}

double GetDFWRate(const College& college, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  
  //
  // TODO:
  //
  //double result=0.0;
    for(auto &dept : college.Depts) {
        for(auto &c : dept.Courses) {
          if (c.getGradingType() == Course::Letter){
        DFW = DFW+c.NumD+c.NumF+c.NumW;
        N = N+c.NumA+c.NumB+c.NumC+c.NumD+c.NumF+c.NumW; 
          }
    }
    }
  if(N==0){
      return 0.0;
  } 
    return ((double)DFW/(double)N)*100.0;
}  


//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c)
{
  
  //
  // TODO:
  //
  GradeStats G;
  if (c.getGradingType() != Course::Letter){
      G.N=0;
      G.NumA=0;
      G.NumB=0;
      G.NumC=0;
      G.NumD=0;
      G.NumF=0;
      G.PercentA=0;
      G.PercentB=0;
      G.PercentC=0;
      G.PercentD=0;
      G.PercentF=0;
}
    else{
        G.N=c.NumA+c.NumB+c.NumC+c.NumD+c.NumF;
        G.NumA=c.NumA;
        G.NumB=c.NumB;
        G.NumC=c.NumC;
        G.NumD=c.NumD;
        G.NumF=c.NumF;
        G.PercentA=((double)G.NumA/(double)G.N)*100.0;
        G.PercentB=((double)G.NumB/(double)G.N)*100.0;
        G.PercentC=((double)G.NumC/(double)G.N)*100.0;
        G.PercentD=((double)G.NumD/(double)G.N)*100.0;
        G.PercentF=((double)G.NumF/(double)G.N)*100.0;
    }
  return G;  
}

GradeStats GetGradeDistribution(const Dept& dept)
{
  
  //
  // TODO:
  //
  GradeStats F;
    //int DN=0;
    int DNumA=0;
    int DNumB=0;
    int DNumC=0;
    int DNumD=0;
    int DNumF=0;
    
    for(const Course&c: dept.Courses) {
       if (c.getGradingType() == Course::Letter){
                DNumA+=c.NumA;
                DNumB+=c.NumB;
                DNumC+=c.NumC;
                DNumD+=c.NumD;
                DNumF+=c.NumF;
                F.N=DNumA+DNumB+DNumC+DNumD+DNumF;
                F.NumA=DNumA;
                F.NumB=DNumB;
                F.NumC=DNumC;
                F.NumD=DNumD;
                F.NumF=DNumF;
                F.PercentA=((double)F.NumA/(double)F.N)*100.0;
                F.PercentB=((double)F.NumB/(double)F.N)*100.0;
                F.PercentC=((double)F.NumC/(double)F.N)*100.0;
                F.PercentD=((double)F.NumD/(double)F.N)*100.0;
                F.PercentF=((double)F.NumF/(double)F.N)*100.0;
                
       }
    }
  return GradeStats(F);
}

GradeStats GetGradeDistribution(const College& college)
{
  
  //
  // TODO:
  //
  GradeStats F;
   // int DN=0;
    int DNumA=0;
    int DNumB=0;
    int DNumC=0;
    int DNumD=0;
    int DNumF=0;
    
    for(const Dept&dept : college.Depts) {
        for(const Course&c : dept.Courses) {
            if (c.getGradingType() == Course::Letter){
                DNumA+=c.NumA;
                DNumB+=c.NumB;
                DNumC+=c.NumC;
                DNumD+=c.NumD;
                DNumF+=c.NumF;
                F.N=DNumA+DNumB+DNumC+DNumD+DNumF;
                F.NumA=DNumA;
                F.NumB=DNumB;
                F.NumC=DNumC;
                F.NumD=DNumD;
                F.NumF=DNumF;
                F.PercentA=((double)F.NumA/(double)F.N)*100.0;
                F.PercentB=((double)F.NumB/(double)F.N)*100.0;
                F.PercentC=((double)F.NumC/(double)F.N)*100.0;
                F.PercentD=((double)F.NumD/(double)F.N)*100.0;
                F.PercentF=((double)F.NumF/(double)F.N)*100.0;
                
            }
         }
    }
    return GradeStats(F);
}


//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
  vector<Course>  courses;
  
  //
  // TODO:
  //
  for(const Course&c : dept.Courses) {
      if(courseNumber==c.Number){
          courses.push_back(c);
      }
  }
  sort(courses.begin(), courses.end(), [](Course s1, Course s2)
       {
      // primary sort by avg, descending:
      if (s1.Section < s2.Section)
          return true;
      else
          return false;
       }
      );
    
  return courses;
}


//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
  vector<Course>  courses;
  
  //
  // TODO:
  //
  for(const Course&c : dept.Courses) {
     // string str = c.Instructor.substr (0,2);
      if(c.Instructor.find(instructorPrefix) != string::npos){
          courses.push_back(c);
      }
  }
  sort(courses.begin(), courses.end(), [](Course s1, Course s2){
      // primary sort by avg, descending:
      if (s1.Number < s2.Number)
          return true;
      else if (s1.Number > s2.Number)
          return false;
      else // equal, secondary sort by name:
          if (s1.Section < s2.Section)
              return true;
          else if(s1.Section > s2.Section)
              return false;
      else
          return false;
  });

  return courses;
}


//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, int courseNumber)
{
  vector<Course>  courses;
  
  //
  // TODO:
  //
  for(auto &dept : college.Depts) {
      for(const Course&c : dept.Courses) {
          if(courseNumber==c.Number){
          courses.push_back(c);
      }
      }
  }
  sort(courses.begin(), courses.end(), [](Course s1, Course s2){
      // primary sort by avg, descending:
      if (s1.Dept < s2.Dept)
          return true;
      else if (s1.Dept > s2.Dept)
          return false;
      else // equal, secondary sort by name:
          if (s1.Number < s2.Number)
              return true;
          else if (s1.Number > s2.Number)
              return false;
          else
              if(s1.Section < s2.Section)
                  return true;
         /* else
              return false;*/
      else
          return false;
  });
  
  return courses;
}


//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
  vector<Course>  courses;
  
  //
  // TODO:
  //
  for(auto &dept : college.Depts) {
      for(const Course&c : dept.Courses) {
          //string str = c.Instructor.substr (0,2);
          if(c.Instructor.find(instructorPrefix) != string::npos){
          courses.push_back(c);
          }
      }
  }
    sort(courses.begin(), courses.end(), [](Course s1, Course s2){
      // primary sort by avg, ascending:
      if (s1.Instructor.compare(s2.Instructor) < 0)
          return true;
      else if (s1.Instructor.compare(s2.Instructor) > 0)
          return false;
      else // equal, secondary sort by name:
          if (s1.Number < s2.Number)
              return true;
          else if (s1.Number > s2.Number)
              return false;
          else
              if(s1.Section < s2.Section)
                  return true;
          else
              return false;
  });
  return courses;
}