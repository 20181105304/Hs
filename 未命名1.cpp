#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <process.h>
#include <Windows.h>
#include <iostream>

using namespace std;

IplImage* IFrameBody = 0;
IplImage* gray = 0;
int red_cnt;
int no_cnt;
bool state;
bool last_state;
short value = 1;
int height, width;
CvCapture* pcap;

char Decide(short i)
{
        char ch = '*';
        switch(i){
        case 5:
                ch = 'A';
                break;
        case 24:
                ch = 'B';
                break;
        case 26:
                ch = 'C';
                break;
        case 12:
                ch = 'D';
                break;
        case 2:
                ch = 'E';
                break;
        case 18:
                ch = 'F';
                break;
        case 14:
                ch = 'G';
                break;
        case 16:
                ch = 'H';
                break;
        case 4:
                ch = 'I';
                break;
        case 23:
                ch = 'J';
                break;
        case 13:
                ch = 'K';
                break;
        case 20:
                ch = 'L';
                break;
        case 7:
                ch = 'M';
                break;
        case 6:
                ch = 'N';
                break;
        case 15:
                ch = 'O';
                break;
        case 22:
                ch = 'P';
                break;
        case 29:
                ch = 'Q';
                break;
        case 10:
                ch = 'R';
                break;
        case 8:
                ch = 'S';
                break;
        case 3:
                ch = 'T';
                break;
        case 9:
                ch = 'U';
                break;
        case 17:
                ch = 'V';
                break;
        case 11:
                ch = 'W';
                break;
        case 25:
                ch = 'X';
                break;
        case 27:
                ch = 'Y';
                break;
        case 28:
                ch = 'Z';
                break;
        default:
                ch = '*';
                break;
        }
        return ch;
}

int main(int argc, char* argv[])
{
        CvCapture* pCapBody = cvCreateCameraCapture(1);

        if(pCapBody == NULL)
        {
                printf("No body camera!!!!!!!!\n");
        }
       
        red_cnt = 0;
        no_cnt = 0;
        state = false;        // false代表无色，true代表检测到白色
        last_state = false;

        while(1)
        {
                IFrameBody = cvQueryFrame(pCapBody);
                if(IFrameBody == NULL)
                {
                        printf("No Pictures.\n");
                }

                height = IFrameBody->height;
                width = IFrameBody->width;
                gray = cvCreateImage(cvSize(width,height),8,1);        // 创建灰度图像

                int count = 0;

                /* 检测白色光 */
                cvCvtColor(IFrameBody, gray, CV_BGR2GRAY);
                for(int i = 220; i < 320; i++)
                {
                        for(int j = 300; j < 400; j++)
                        {
                                int g = ((uchar*)(gray->imageData+gray->widthStep*j))[i];
                                if(g>150)
                                {
                                        count += 1;
                                        ((uchar*)(gray->imageData+gray->widthStep*j))[i] = 255;
                                }
                                else
                                {
                                        ((uchar*)(gray->imageData+gray->widthStep*j))[i] = 0;
                                }
                        }
                }

                if(count > 1500)        // 检测“白色”，1500是像素点阈值
                {
                        state = true;
                        if(last_state == false)
                        {
                                if(no_cnt > 10 && no_cnt < 35)        // 说明是字符间间隔,no_cnt是持续检测到“无色”的次数，10和35是阈值
                                {
                                        cout<<Decide(value);
                                        value = 1;
                                }
                                else if(no_cnt > 35)        // 说明是单词间间隔
                                {
                                        cout<<Decide(value)<<" ";
                                        value = 1;
                                }
                                no_cnt = 0;
                                red_cnt = 0;
                        }
                        red_cnt++;
                }
                else        // 检测到“无色”
                {
                        state = false;
                        if(last_state == true)
                        {
                                if(red_cnt >= 10)        // 检测到“白色”十次以上，判断为“_”，阈值10可调
                                {
                                        value = (value << 1) + 1;
                                }
                                else if(red_cnt < 10)        // 检测到“白色”的时间很短，判断为“.”
                                {
                                        value = value << 1;
                                }
                                red_cnt = 0;
                                no_cnt = 0;
                        }
                        no_cnt++;
                }

                last_state = state;
               
                cvShowImage("gray", gray);

                cvReleaseImage(&gray);

                char c=cvWaitKey(1);
                if(c==27)break;
        }

        cvReleaseCapture(&pCapBody);

}
