// Read destination image.
    Mat im_dst = imread("traffic.jpg");
    // Four corners of the book in destination image.
    vector<Point2f> pts_dst;
    pts_dst.push_back(Point2f(472,52));
    pts_dst.push_back(Point2f(800,52));
    pts_dst.push_back(Point2f(472,830));
    pts_dst.push_back(Point2f(800, 830));

    // Calculate Homography
    Mat h = findHomography(pts_src, pts_dst);

    //Output image
    Mat im_out;
    //Warp source image to destination based on homography
    warpPerspective(img, im_out, h, im_dst.size());

    // Display images
    imshow("Source Image", img);
    imshow("Destination Image", im_dst);
    imshow("Warped Source Image", im_out);
    //vector<Point> locations;   // output, locations of non-zero pixels
    //findNonZero(img, locations);
    // access pixel coordinates
    // Point pnt = locations[0];
    // cout<<pnt<<"\n";
   
//    for (int i = 0; i < img.cols; i++ ) {
//         for (int j = 0; j < img.rows; j++) {
//             if (img.at<uchar>(j, i) > 0) {  
//                    // Do your operations
//             }
//         }
//     }
    

    //cv::Mat binaryImage; // input, binary image


    // cout<<img.cols<<"\n";
    // cout<<img.rows<<"\n";
    // ///imshow("Display window", img);
    // auto squareSize=8;
    // vector<Point2f> corners;
    // vector<Point3f> objectPoints;
    // bool found = findChessboardCorners(img, cv::Size(img.cols,img.rows), corners);
    //         for( int i = 0; i < img.rows; i++ ){
    //           for( int j = 0; j < img.cols; j++ ){
    //             objectPoints.push_back(Point3f(float(j*squareSize),float(i*squareSize),0));
    //           }
    //         }


   // calcChessboardCorners(cv::Size(img.cols,img.rows), squareSize, objectPoints);
    // vector<Point2f> objectPointsPlanar;
    // for (size_t i = 0; i < objectPoints.size(); i++)
    // {
    //     objectPointsPlanar.push_back(Point2f(objectPoints[i].x, objectPoints[i].y));
    // }

    //  FileStorage fs( samples::findFile("test.jpg" ), FileStorage::READ);
    // Mat cameraMatrix, distCoeffs;
    // fs["camera_matrix"] >> cameraMatrix;
    // fs["distortion_coefficients"] >> distCoeffs;

    // vector<Point2f> imagePoints;
    // undistortPoints(corners, imagePoints, cameraMatrix, distCoeffs);

    //     Mat H = findHomography(objectPointsPlanar, imagePoints);
      // cout << "H:\n" << H << endl;

    //     // Normalization to ensure that ||c1|| = 1
    // double norm = sqrt(H.at<double>(0,0)*H.at<double>(0,0) +
    //                    H.at<double>(1,0)*H.at<double>(1,0) +
    //                    H.at<double>(2,0)*H.at<double>(2,0));
    // H /= norm;
    // Mat c1  = H.col(0);
    // Mat c2  = H.col(1);
    // Mat c3 = c1.cross(c2);
    // Mat tvec = H.col(2);
    // Mat R(3, 3, CV_64F);
    // for (int i = 0; i < 3; i++)
    // {
    //     R.at<double>(i,0) = c1.at<double>(i,0);
    //     R.at<double>(i,1) = c2.at<double>(i,0);
    //     R.at<double>(i,2) = c3.at<double>(i,0);
    // }

    //     cout << "R (before polar decomposition):\n" << R << "\ndet(R): " << determinant(R) << endl;
    // Mat W, U, Vt;
    // SVDecomp(R, W, U, Vt);
    // R = U*Vt;
    // cout << "R (after polar decomposition):\n" << R << "\ndet(R): " << determinant(R) << endl;
    waitKey(0); 