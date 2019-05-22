#include"stamanagement.h"


void stamanagement::stuinput(){
  QStringList list;
  for(int k=0;k<m_staff.size();k++){
  for(int i=1;i<m_student.size();i++){
      for(int j=0;j<m_student[i].m_les.size();j++){
          list=m_staff[k].getteachles().split("/");
          int m(0);
          for(int n=0;n<list.size();n++){
          if(m_student[i].m_les[j].getmodname()==list[n]) m++;
          }
          if(m==0)  continue;
          else {
              int x(0);
              for(int s=0;s<m_staff[k].m_stu.size();s++){
                  if(m_staff[k].m_stu[s].getID()==m_student[i].getID()) x++;
              }
             if(x==0){ m_staff[k].m_stu.push_back(m_student[i]);}
          }
      }

  }
  }


}
