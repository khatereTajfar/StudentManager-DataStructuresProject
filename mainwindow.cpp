#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->display(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked() //Add Button
{
    if(ui->lineEdit1->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty()
            ||(!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()) ||ui->lineEdit_4->text().isEmpty())
        messageBox.information(this,"Warning!","Fill The Blanks!");
    else{
        QString name=ui->lineEdit1->text();
        QString familyName=ui->lineEdit_2->text();
        int identityCode=ui->lineEdit_3->text().toInt();
        int enteringYear=ui->comboBox->currentText().toInt();
        if(ui->radioButton->isChecked())
            tendency="Software";
        else if(ui->radioButton_2->isChecked())
            tendency="Hardware";
        double average=ui->lineEdit_4->text().toDouble();

        if(BST.BSTInsertFamilyName(name,familyName,identityCode,enteringYear,tendency,average) &&
                BST2.BSTInsertAverage(name,familyName,identityCode,enteringYear,tendency,average)){
            counter++;
            ui->lcdNumber->display(counter);
            messageBox.information(this,"Add Function","Student with this information:\nName:"
                                   +name+"\nLast Name:"+familyName+"\nIdentity Code:"+ui->lineEdit_3->text()+"\nEntering year:"+ui->comboBox->currentText()
                                   +"\nTendency:"+tendency+"\nAverage:"+ui->lineEdit_4->text()+"\nadded successfully.");
            //convertin Qstrings too *char because of "COUT" :D
            QByteArray ba1 = familyName.toLatin1();
            const char *familyName1 = ba1.data();
            QByteArray ba2 = name.toLatin1();
            const char *name1 = ba2.data();
            QByteArray ba3 = tendency.toLatin1();
            const char *tendency1 = ba3.data();
            cout<<"<<Add By Family Name>> and <<Add By Average>> functions were called and student with this information:"<<"\n"<<"NAME: "<<name1<<"\n"<<"FAMILY NAME: "<<familyName1<<"\n"
               <<"IDENTITY CODE: "<<identityCode<<"\n"<<"ENTERING YEAR: "<<enteringYear<<"\n"<<"TENDENCY: "<<tendency1<<"\n"<<"AVERAGE: "<<average<<"\n"<<"added sucssesfully in BSTs\n";
            cout<<"_____________________________________________________________________________________________\n";
        }
        else{
            messageBox.information(this,tr("Warning!"),"Student with Identity Code of "+ui->lineEdit_3->text()+" already exists!");
            cout<<"student with Identity Code of "<<identityCode<< " already exists\n";
        }
        //clearing the linEdits and radioBoxes for new informations
        ui->lineEdit1->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->radioButton->setAutoExclusive(false);
        ui->radioButton->setChecked(false);
        ui->radioButton->setAutoExclusive(false);
        ui->radioButton_2->setAutoExclusive(false);
        ui->radioButton_2->setChecked(false);
        ui->radioButton_2->setAutoExclusive(false);
    }
}

void MainWindow::on_pushButton_clicked()//search button
{
    QString IdentityCode,EnteringYear,Average;
    if(!ui->lineEdit_5->text().isEmpty()){
        QString familyName=ui->lineEdit_5->text();
        if(Student *t=BST.SearchByFamilyName(familyName)){
            messageBox.information(this,"Search","Informations of student with last name of <<"+familyName+">> is:\nName:"
                                   +t->Name+"\nLast Name:"+t->FamilyName+"\nIdentity Code:"+IdentityCode.setNum( t->IdentityCode)+"\nEntering year:"+EnteringYear.setNum( t->EnteringYear)
                                   +"\nTendency:"+t->Tendency+"\nAverage:"+Average.setNum( t->Average));
        }
        else
            messageBox.information(this,"Search","student with last name of <<"+familyName+">> does not exist.");
        ui->lineEdit_5->clear();
    }else if(!ui->lineEdit_6->text().isEmpty()) {
        int identityCode=ui->lineEdit_6->text().toInt();
        if(Student *t=BST.SearchByIdentityCode(identityCode))
            messageBox.information(this,"Search","Informations of student with identity code of <<"+ui->lineEdit_6->text()+">> is:\nName:"
                                   +t->Name+"\nLast Name:"+t->FamilyName+"\nIdentity Code:"+IdentityCode.setNum( t->IdentityCode)+"\nEntering year:"+EnteringYear.setNum( t->EnteringYear)
                                   +"\nTendency:"+t->Tendency+"\nAverage:"+Average.setNum( t->Average));
        else
            messageBox.information(this,"Search","student with identity code of <<"+ui->lineEdit_6->text()+">> does not exist.");
        ui->lineEdit_6->clear();
    }

}


void MainWindow::on_pushButton_2_clicked()//listing students by family name
{
    BST.InorderFamilyName();
}

void MainWindow::on_pushButton_3_clicked() //listing student by average
{
    BST2.InorderAverage();
}


