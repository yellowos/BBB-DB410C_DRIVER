#include <iostream>
#include <unp.h>
#include "get_image.h"
#include <opencv2/opencv.hpp>
#include "parameters.h"


using namespace cv;
int main() {
    int listenfd, connfd;
    struct sockaddr_in cliaddr, servaddr;
    socklen_t clilen;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);
    clilen = sizeof(cliaddr);
    //ctrlfd = accept(listenfd, (SA *) &cliaddr, &clilen);
    printf("ok\n");
    connfd = accept(listenfd, (SA *) &cliaddr, &clilen);
    printf("connect!\n");


    char data_size_array[4];
    while (true) {


        unsigned int data_size;
        get_image(connfd, data_size_array, sizeof(unsigned int));
        write(connfd, "2", 2);
        data_size = *(unsigned int *)data_size_array;
        //printf("%d\n", data_size);
        //data_size = atoi(data_size_array);
        printf("data_size:%d\n", data_size);
        //buf = (char *)calloc(data_size, sizeof(char));


        printf("try get image\n");
//        buf = (char *)calloc(data_size, sizeof(char));
//        memset(buf, 0xFF, data_size);
        char  buf[400000] = {0};
//        memset(buf, 0x00, 400000);
        get_image(connfd, (char *)buf, data_size);
        std::vector<char> data_image;
        for(int n = 0; n < data_size; n++){
            data_image.push_back(buf[n]);
        }

        printf("get image finish\n");
        write(connfd, "1", 2);

//        data_image = (std::vector<char> *)buf;

//        get_image(connfd, (char *)&frame.at<int>(0, 0), IMAGE_WIDTH * IMAGE_HIGH*2);
//        Mat output_frame(IMAGE_HIGH, IMAGE_WIDTH, CV_8UC1, );
//        for(int y = 0; y < IMAGE_HIGH; y++){
//            for(int x = 0; x < IMAGE_WIDTH; x++){
//                output_frame.at<char>(y, x) = frame.at<int>(y, x/2);
//            }
//        }
        /*Mat frame(IMAGE_HIGH, IMAGE_WIDTH, CV_8UC3, (void *)(buf));
        if(buf[0] == 0xFF && buf[1] == 0xD8){
            printf("head ok!\n");
        }
        if(buf[data_size-2] == 0xFF && buf[data_size - 1] == 0xD9){
            printf("end ok!\n");
        }
        else{
            for(int k = 0; k < 400000; k++){

            }
        }*/
        Mat frame(IMAGE_HIGH, IMAGE_WIDTH, CV_8UC1);
        printf("try to decode\n");
        imdecode(data_image, CV_LOAD_IMAGE_GRAYSCALE, &frame);
        printf("finish image decode\n");
        //memcpy(&frame.at<char>(0, 0), buf, IMAGE_WIDTH * IMAGE_HIGH * 2);
        imshow("output", frame);
        waitKey(1);
        printf("display ok");
//        memset(buf, 0, 400000);
        //       free(buf);
//        printf("free finish\n");
        //buf = nullptr;
        //close(connfd);
        //printf("finish get image\n");



        /*if (fork() == 0) {
            printf("wait connect\n");
            connfd = accept(listenfd, (SA *) &cliaddr, &clilen);
            get_image(connfd);
            close(connfd);
            printf("finish connect\n\n");
            exit(0);
        } else {
            wait(nullptr);
            write(ctrlfd, "1", 2);
        }*/
    }
    return 0;
}

