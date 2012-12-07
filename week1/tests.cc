// Implementation of RTL tests
#include <iostream>

#include "tests.h"
#include "vector.h"
#include "sort.h"
#include <Windows.h>

namespace rtl
{
namespace tests
{


int testArray[] = 
{
520, 869, 893, 618, 885, 449, 467, 580, 114, 792,
465, 697, 34, 669, 207, 269, 960, 288, 670, 968,
260, 155, 524, 412, 663, 482, 93, 80, 598, 600,
242, 477, 138, 877, 930, 32, 671, 476, 768, 667,
803, 357, 723, 371, 259, 522, 591, 908, 604, 323,
983, 159, 635, 981, 235, 684, 228, 447, 939, 814,
872, 590, 777, 349, 194, 978, 514, 132, 245, 104,
485, 191, 728, 556, 958, 150, 117, 53, 218, 599,
763, 472, 307, 708, 509, 359, 362, 42, 712, 564,
741, 226, 280, 40, 886, 75, 824, 424, 434, 408,
505, 780, 332, 917, 587, 169, 933, 828, 224, 498,
685, 528, 284, 560, 203, 343, 749, 500, 683, 333,
1, 492, 249, 365, 699, 997, 502, 426, 882, 980,
826, 205, 624, 111, 152, 626, 567, 372, 19, 845,
813, 762, 176, 10, 539, 974, 299, 298, 746, 938,
118, 435, 153, 856, 668, 279, 355, 328, 719, 81,
123, 918, 9, 489, 246, 456, 317, 388, 661, 732,
387, 14, 793, 948, 353, 743, 734, 351, 219, 838,
627, 903, 491, 56, 680, 876, 819, 265, 70, 584,
309, 922, 822, 306, 445, 234, 146, 825, 395, 37,
932, 6, 84, 167, 73, 273, 926, 65, 802, 649,
551, 416, 689, 177, 975, 811, 832, 329, 291, 225,
361, 213, 182, 977, 483, 308, 912, 36, 607, 421,
901, 223, 342, 301, 799, 812, 35, 904, 515, 987,
681, 801, 758, 639, 920, 852, 433, 356, 15, 881,
200, 740, 503, 103, 418, 835, 99, 554, 468, 145,
451, 461, 457, 765, 386, 971, 18, 295, 729, 22,
721, 350, 899, 473, 270, 201, 352, 274, 902, 782,
69, 238, 85, 193, 335, 653, 760, 613, 0, 853,
16, 862, 804, 795, 701, 79, 959, 17, 632, 544,
161, 540, 506, 589, 217, 96, 868, 637, 61, 800,
783, 841, 168, 4, 374, 160, 935, 410, 745, 722,
557, 275, 736, 678, 229, 162, 430, 942, 136, 713,
23, 855, 839, 911, 778, 82, 458, 170, 139, 11,
494, 654, 484, 583, 815, 283, 185, 380, 787, 834,
97, 695, 543, 368, 74, 310, 575, 988, 534, 727,
724, 954, 31, 924, 956, 135, 709, 233, 619, 972,
127, 475, 631, 696, 615, 816, 770, 495, 481, 320,
391, 943, 286, 742, 67, 909, 854, 92, 83, 340,
422, 262, 285, 913, 183, 630, 8, 568, 394, 611,
658, 463, 606, 894, 68, 240, 785, 409, 407, 990,
529, 39, 831, 251, 367, 129, 471, 895, 871, 786,
393, 429, 326, 638, 957, 716, 385, 464, 296, 49,
750, 94, 706, 24, 597, 195, 994, 847, 20, 192,
321, 212, 662, 478, 527, 963, 873, 674, 370, 889,
805, 341, 21, 287, 125, 411, 442, 784, 809, 744,
602, 634, 864, 316, 55, 453, 497, 794, 414, 339,
436, 542, 300, 230, 677, 444, 652, 460, 751, 107,
711, 122, 807, 263, 569, 276, 700, 133, 846, 389,
148, 692, 344, 501, 334, 57, 25, 140, 199, 965,
437, 533, 211, 717, 305, 89, 753, 843, 927, 718,
752, 641, 931, 264, 381, 171, 705, 253, 566, 848,
574, 622, 682, 337, 796, 836, 612, 883, 254, 550,
470, 610, 76, 354, 281, 829, 277, 504, 844, 3,
154, 58, 810, 312, 90, 462, 232, 164, 769, 151,
175, 536, 673, 929, 967, 179, 748, 256, 592, 690,
149, 660, 821, 620, 878, 519, 806, 947, 507, 59,
656, 420, 851, 616, 798, 766, 837, 998, 231, 186,
128, 964, 944, 60, 789, 820, 166, 866, 72, 392,
236, 579, 214, 425, 282, 771, 961, 313, 863, 532,
423, 772, 603, 773, 216, 178, 571, 113, 432, 347,
945, 187, 790, 244, 537, 158, 12, 757, 46, 982,
487, 63, 976, 358, 970, 720, 404, 525, 454, 413,
322, 754, 41, 452, 526, 582, 378, 115, 644, 759,
541, 993, 197, 657, 940, 202, 791, 324, 38, 440,
694, 962, 252, 857, 66, 581, 687, 255, 366, 499,
608, 642, 517, 419, 715, 552, 95, 898, 188, 538,
479, 545, 271, 377, 137, 30, 915, 360, 923, 44,
54, 206, 258, 221, 984, 688, 986, 45, 651, 890,
204, 781, 605, 266, 905, 131, 679, 818, 459, 989,
116, 779, 511, 110, 363, 693, 865, 91, 293, 157,
518, 513, 969, 609, 448, 397, 645, 222, 124, 272,
523, 647, 623, 325, 508, 614, 119, 578, 747, 594,
646, 896, 248, 26, 364, 936, 703, 198, 892, 561,
726, 817, 707, 842, 733, 636, 875, 5, 949, 427,
946, 937, 318, 625, 738, 50, 992, 833, 382, 704,
521, 731, 348, 576, 775, 156, 428, 315, 29, 633,
88, 546, 548, 488, 553, 402, 979, 48, 474, 891,
331, 290, 163, 480, 861, 490, 383, 33, 531, 64,
767, 446, 563, 303, 995, 665, 493, 860, 384, 730,
241, 208, 880, 907, 710, 530, 147, 181, 914, 764,
549, 827, 973, 761, 512, 438, 173, 808, 121, 396,
400, 788, 189, 379, 62, 725, 859, 486, 593, 466,
698, 78, 77, 415, 439, 278, 655, 98, 106, 126,
209, 941, 858, 659, 28, 86, 143, 302, 496, 43,
565, 951, 952, 547, 227, 406, 239, 257, 628, 985,
190, 184, 369, 51, 702, 267, 573, 243, 450, 165,
180, 100, 297, 215, 294, 27, 849, 345, 776, 916,
714, 237, 174, 919, 130, 562, 950, 314, 101, 906,
596, 102, 888, 87, 338, 375, 535, 403, 601, 555,
373, 443, 756, 991, 588, 850, 210, 621, 401, 996,
469, 934, 52, 405, 737, 142, 570, 921, 830, 105,
675, 327, 304, 739, 346, 774, 900, 928, 141, 755,
999, 879, 955, 910, 108, 577, 643, 672, 47, 617,
431, 558, 336, 516, 572, 664, 510, 559, 311, 289,
330, 925, 398, 648, 686, 897, 376, 797, 13, 71,
691, 586, 7, 840, 319, 196, 261, 676, 250, 455,
292, 870, 390, 120, 247, 650, 874, 629, 953, 220,
134, 823, 884, 666, 867, 144, 640, 441, 735, 2,
417, 112, 966, 595, 585, 172, 109, 399, 268, 887
};

int expected[] = 
{
0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
160, 161, 162, 163, 164, 165, 166, 167, 168, 169,
170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
180, 181, 182, 183, 184, 185, 186, 187, 188, 189,
190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
220, 221, 222, 223, 224, 225, 226, 227, 228, 229,
230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
240, 241, 242, 243, 244, 245, 246, 247, 248, 249,
250, 251, 252, 253, 254, 255, 256, 257, 258, 259,
260, 261, 262, 263, 264, 265, 266, 267, 268, 269,
270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
280, 281, 282, 283, 284, 285, 286, 287, 288, 289,
290, 291, 292, 293, 294, 295, 296, 297, 298, 299,
300, 301, 302, 303, 304, 305, 306, 307, 308, 309,
310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
320, 321, 322, 323, 324, 325, 326, 327, 328, 329,
330, 331, 332, 333, 334, 335, 336, 337, 338, 339,
340, 341, 342, 343, 344, 345, 346, 347, 348, 349,
350, 351, 352, 353, 354, 355, 356, 357, 358, 359,
360, 361, 362, 363, 364, 365, 366, 367, 368, 369,
370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
380, 381, 382, 383, 384, 385, 386, 387, 388, 389,
390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
400, 401, 402, 403, 404, 405, 406, 407, 408, 409,
410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
420, 421, 422, 423, 424, 425, 426, 427, 428, 429,
430, 431, 432, 433, 434, 435, 436, 437, 438, 439,
440, 441, 442, 443, 444, 445, 446, 447, 448, 449,
450, 451, 452, 453, 454, 455, 456, 457, 458, 459,
460, 461, 462, 463, 464, 465, 466, 467, 468, 469,
470, 471, 472, 473, 474, 475, 476, 477, 478, 479,
480, 481, 482, 483, 484, 485, 486, 487, 488, 489,
490, 491, 492, 493, 494, 495, 496, 497, 498, 499,
500, 501, 502, 503, 504, 505, 506, 507, 508, 509,
510, 511, 512, 513, 514, 515, 516, 517, 518, 519,
520, 521, 522, 523, 524, 525, 526, 527, 528, 529,
530, 531, 532, 533, 534, 535, 536, 537, 538, 539,
540, 541, 542, 543, 544, 545, 546, 547, 548, 549,
550, 551, 552, 553, 554, 555, 556, 557, 558, 559,
560, 561, 562, 563, 564, 565, 566, 567, 568, 569,
570, 571, 572, 573, 574, 575, 576, 577, 578, 579,
580, 581, 582, 583, 584, 585, 586, 587, 588, 589,
590, 591, 592, 593, 594, 595, 596, 597, 598, 599,
600, 601, 602, 603, 604, 605, 606, 607, 608, 609,
610, 611, 612, 613, 614, 615, 616, 617, 618, 619,
620, 621, 622, 623, 624, 625, 626, 627, 628, 629,
630, 631, 632, 633, 634, 635, 636, 637, 638, 639,
640, 641, 642, 643, 644, 645, 646, 647, 648, 649,
650, 651, 652, 653, 654, 655, 656, 657, 658, 659,
660, 661, 662, 663, 664, 665, 666, 667, 668, 669,
670, 671, 672, 673, 674, 675, 676, 677, 678, 679,
680, 681, 682, 683, 684, 685, 686, 687, 688, 689,
690, 691, 692, 693, 694, 695, 696, 697, 698, 699,
700, 701, 702, 703, 704, 705, 706, 707, 708, 709,
710, 711, 712, 713, 714, 715, 716, 717, 718, 719,
720, 721, 722, 723, 724, 725, 726, 727, 728, 729,
730, 731, 732, 733, 734, 735, 736, 737, 738, 739,
740, 741, 742, 743, 744, 745, 746, 747, 748, 749,
750, 751, 752, 753, 754, 755, 756, 757, 758, 759,
760, 761, 762, 763, 764, 765, 766, 767, 768, 769,
770, 771, 772, 773, 774, 775, 776, 777, 778, 779,
780, 781, 782, 783, 784, 785, 786, 787, 788, 789,
790, 791, 792, 793, 794, 795, 796, 797, 798, 799,
800, 801, 802, 803, 804, 805, 806, 807, 808, 809,
810, 811, 812, 813, 814, 815, 816, 817, 818, 819,
820, 821, 822, 823, 824, 825, 826, 827, 828, 829,
830, 831, 832, 833, 834, 835, 836, 837, 838, 839,
840, 841, 842, 843, 844, 845, 846, 847, 848, 849,
850, 851, 852, 853, 854, 855, 856, 857, 858, 859,
860, 861, 862, 863, 864, 865, 866, 867, 868, 869,
870, 871, 872, 873, 874, 875, 876, 877, 878, 879,
880, 881, 882, 883, 884, 885, 886, 887, 888, 889,
890, 891, 892, 893, 894, 895, 896, 897, 898, 899,
900, 901, 902, 903, 904, 905, 906, 907, 908, 909,
910, 911, 912, 913, 914, 915, 916, 917, 918, 919,
920, 921, 922, 923, 924, 925, 926, 927, 928, 929,
930, 931, 932, 933, 934, 935, 936, 937, 938, 939,
940, 941, 942, 943, 944, 945, 946, 947, 948, 949,
950, 951, 952, 953, 954, 955, 956, 957, 958, 959,
960, 961, 962, 963, 964, 965, 966, 967, 968, 969,
970, 971, 972, 973, 974, 975, 976, 977, 978, 979,
980, 981, 982, 983, 984, 985, 986, 987, 988, 989,
990, 991, 992, 993, 994, 995, 996, 997, 998, 999
};

int worstCase[] =
{
999, 998, 997, 996, 995, 994, 993, 992, 991, 990,
989, 988, 987, 986, 985, 984, 983, 982, 981, 980,
979, 978, 977, 976, 975, 974, 973, 972, 971, 970,
969, 968, 967, 966, 965, 964, 963, 962, 961, 960,
959, 958, 957, 956, 955, 954, 953, 952, 951, 950,
949, 948, 947, 946, 945, 944, 943, 942, 941, 940,
939, 938, 937, 936, 935, 934, 933, 932, 931, 930,
929, 928, 927, 926, 925, 924, 923, 922, 921, 920,
919, 918, 917, 916, 915, 914, 913, 912, 911, 910,
909, 908, 907, 906, 905, 904, 903, 902, 901, 900,
899, 898, 897, 896, 895, 894, 893, 892, 891, 890,
889, 888, 887, 886, 885, 884, 883, 882, 881, 880,
879, 878, 877, 876, 875, 874, 873, 872, 871, 870,
869, 868, 867, 866, 865, 864, 863, 862, 861, 860,
859, 858, 857, 856, 855, 854, 853, 852, 851, 850,
849, 848, 847, 846, 845, 844, 843, 842, 841, 840,
839, 838, 837, 836, 835, 834, 833, 832, 831, 830,
829, 828, 827, 826, 825, 824, 823, 822, 821, 820,
819, 818, 817, 816, 815, 814, 813, 812, 811, 810,
809, 808, 807, 806, 805, 804, 803, 802, 801, 800,
799, 798, 797, 796, 795, 794, 793, 792, 791, 790,
789, 788, 787, 786, 785, 784, 783, 782, 781, 780,
779, 778, 777, 776, 775, 774, 773, 772, 771, 770,
769, 768, 767, 766, 765, 764, 763, 762, 761, 760,
759, 758, 757, 756, 755, 754, 753, 752, 751, 750,
749, 748, 747, 746, 745, 744, 743, 742, 741, 740,
739, 738, 737, 736, 735, 734, 733, 732, 731, 730,
729, 728, 727, 726, 725, 724, 723, 722, 721, 720,
719, 718, 717, 716, 715, 714, 713, 712, 711, 710,
709, 708, 707, 706, 705, 704, 703, 702, 701, 700,
699, 698, 697, 696, 695, 694, 693, 692, 691, 690,
689, 688, 687, 686, 685, 684, 683, 682, 681, 680,
679, 678, 677, 676, 675, 674, 673, 672, 671, 670,
669, 668, 667, 666, 665, 664, 663, 662, 661, 660,
659, 658, 657, 656, 655, 654, 653, 652, 651, 650,
649, 648, 647, 646, 645, 644, 643, 642, 641, 640,
639, 638, 637, 636, 635, 634, 633, 632, 631, 630,
629, 628, 627, 626, 625, 624, 623, 622, 621, 620,
619, 618, 617, 616, 615, 614, 613, 612, 611, 610,
609, 608, 607, 606, 605, 604, 603, 602, 601, 600,
599, 598, 597, 596, 595, 594, 593, 592, 591, 590,
589, 588, 587, 586, 585, 584, 583, 582, 581, 580,
579, 578, 577, 576, 575, 574, 573, 572, 571, 570,
569, 568, 567, 566, 565, 564, 563, 562, 561, 560,
559, 558, 557, 556, 555, 554, 553, 552, 551, 550,
549, 548, 547, 546, 545, 544, 543, 542, 541, 540,
539, 538, 537, 536, 535, 534, 533, 532, 531, 530,
529, 528, 527, 526, 525, 524, 523, 522, 521, 520,
519, 518, 517, 516, 515, 514, 513, 512, 511, 510,
509, 508, 507, 506, 505, 504, 503, 502, 501, 500,
499, 498, 497, 496, 495, 494, 493, 492, 491, 490,
489, 488, 487, 486, 485, 484, 483, 482, 481, 480,
479, 478, 477, 476, 475, 474, 473, 472, 471, 470,
469, 468, 467, 466, 465, 464, 463, 462, 461, 460,
459, 458, 457, 456, 455, 454, 453, 452, 451, 450,
449, 448, 447, 446, 445, 444, 443, 442, 441, 440,
439, 438, 437, 436, 435, 434, 433, 432, 431, 430,
429, 428, 427, 426, 425, 424, 423, 422, 421, 420,
419, 418, 417, 416, 415, 414, 413, 412, 411, 410,
409, 408, 407, 406, 405, 404, 403, 402, 401, 400,
399, 398, 397, 396, 395, 394, 393, 392, 391, 390,
389, 388, 387, 386, 385, 384, 383, 382, 381, 380,
379, 378, 377, 376, 375, 374, 373, 372, 371, 370,
369, 368, 367, 366, 365, 364, 363, 362, 361, 360,
359, 358, 357, 356, 355, 354, 353, 352, 351, 350,
349, 348, 347, 346, 345, 344, 343, 342, 341, 340,
339, 338, 337, 336, 335, 334, 333, 332, 331, 330,
329, 328, 327, 326, 325, 324, 323, 322, 321, 320,
319, 318, 317, 316, 315, 314, 313, 312, 311, 310,
309, 308, 307, 306, 305, 304, 303, 302, 301, 300,
299, 298, 297, 296, 295, 294, 293, 292, 291, 290,
289, 288, 287, 286, 285, 284, 283, 282, 281, 280,
279, 278, 277, 276, 275, 274, 273, 272, 271, 270,
269, 268, 267, 266, 265, 264, 263, 262, 261, 260,
259, 258, 257, 256, 255, 254, 253, 252, 251, 250,
249, 248, 247, 246, 245, 244, 243, 242, 241, 240,
239, 238, 237, 236, 235, 234, 233, 232, 231, 230,
229, 228, 227, 226, 225, 224, 223, 222, 221, 220,
219, 218, 217, 216, 215, 214, 213, 212, 211, 210,
209, 208, 207, 206, 205, 204, 203, 202, 201, 200,
199, 198, 197, 196, 195, 194, 193, 192, 191, 190,
189, 188, 187, 186, 185, 184, 183, 182, 181, 180,
179, 178, 177, 176, 175, 174, 173, 172, 171, 170,
169, 168, 167, 166, 165, 164, 163, 162, 161, 160,
159, 158, 157, 156, 155, 154, 153, 152, 151, 150,
149, 148, 147, 146, 145, 144, 143, 142, 141, 140,
139, 138, 137, 136, 135, 134, 133, 132, 131, 130,
129, 128, 127, 126, 125, 124, 123, 122, 121, 120,
119, 118, 117, 116, 115, 114, 113, 112, 111, 110,
109, 108, 107, 106, 105, 104, 103, 102, 101, 100,
99, 98, 97, 96, 95, 94, 93, 92, 91, 90,
89, 88, 87, 86, 85, 84, 83, 82, 81, 80,
79, 78, 77, 76, 75, 74, 73, 72, 71, 70,
69, 68, 67, 66, 65, 64, 63, 62, 61, 60,
59, 58, 57, 56, 55, 54, 53, 52, 51, 50,
49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
39, 38, 37, 36, 35, 34, 33, 32, 31, 30,
29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
9, 8, 7, 6, 5, 4, 3, 2, 1, 0
};



#define TESTINIT(s) \
	bool success = true; \
	std::cerr << s << std::endl; \

#define CHK(x) \
	success = success && (x); \
	if (!success) return false; \

#define CHKS(x,s) \
	success = success && (x); \
	if (!success) \
	{ \
		std::cerr << "\nFAIL: " << s << std::endl << std::endl; \
		return false; \
	} \

// For Verbose logging
#define VRBSLOG(s) \
	if (VerboseLogging::Enabled()) \
		std::cerr << "\t" << s << std::endl; \

#define SUCCESSMSG(s) \
	if (success) \
		std::cerr << s << std::endl; \

#define TESTRETURN \
	return success; \


bool RunSortTests()
{
	TESTINIT("Running sorting tests.\n");

	CHK(MergeSortTest());

	TESTRETURN;
}


template <typename T>
void VrbslogPrintVector(const vector<T>& dut)
{
	for (size_t i = 0; i < dut.size(); ++i)
		VRBSLOG(dut[i]);
}


bool MergeSortTest()
{
	TESTINIT("Running mergesort test.\n");

	//int testArray[] = {2, 3, 5, 1, 4, 6};
	//int worstCase[] = {6, 5, 4, 3, 2, 1};
	//int expected[] = {1, 2, 3, 4, 5, 6};
	vector<int> dut(testArray, testArray + sizeof(testArray)/sizeof(int));
	vector<int> dut1(worstCase, worstCase + sizeof(worstCase)/sizeof(int));
	vector<int> dut2(expected, expected + sizeof(expected)/sizeof(int));

	class IntComparer
	{
	public:
		bool operator()(int param1, int param2)
		{
			return param1 < param2;
		}
	} comparer;

	__int64 timeTest = 0, timeWorstCase = 0, timeAlreadySorted = 0;
	StopWatch sw;

	mergesort(dut.begin(), dut.end(), comparer);
	
	timeTest = sw.GetTickCount();
	sw.Reset();

	mergesort(dut1.begin(), dut1.end(), comparer);

	timeWorstCase = sw.GetTickCount();
	sw.Reset();

	mergesort(dut2.begin(), dut2.end(), comparer);

	timeAlreadySorted = sw.GetTickCount();

	CHKS(std::equal(dut.begin(), dut.end(), expected), "Mergesort didn't sort the test list properly.");
	CHKS(std::equal(dut1.begin(), dut1.end(), expected), "Mergesort didn't sort the worst case list properly.");
	CHKS(std::equal(dut2.begin(), dut2.end(), expected), "Mergesort didn't sort the already-sorted list properly.");
	//VRBSLOG("The test list after mergesort looks like: ");
	//VrbslogPrintVector(dut);
	//VRBSLOG("The worst case list after mergesort looks like: ");
	//VrbslogPrintVector(dut1);
	//VRBSLOG("The already-sorted list after mergesort looks like: ");
	//VrbslogPrintVector(dut2);

	VRBSLOG("Time to sort test list: " << timeTest);
	VRBSLOG("Time to sort worst-case list: " << timeWorstCase);
	VRBSLOG("Time to sort already-sorted list: " << timeAlreadySorted);


	TESTRETURN;
}


bool RunVectorTests()
{
	TESTINIT("Running all rtl::vector<T> tests.\n");

	CHK(VectorIntConstructorTest());
	CHK(VectorIntInsertEraseTest());
	CHK(VectorPushPopTest());

	SUCCESSMSG("\nAll tests completed successfully!\n");

	TESTRETURN;
}


bool VectorIntConstructorTest()
{
	TESTINIT("Running rtl::vector<int> constructor tests.");

	vector<int> dut0(5);
	CHKS(dut0.capacity() >= 5, "1 param constructor: The initializing constructor didn't create a vector with enough capacity.");

	vector<int> dut1(3u, 42);
	CHKS(dut1.capacity() >= 3, "2 param constructor: The initializing constructor didn't create a vector with enough capacity.");
	for (size_t i = 0; i < 3u; ++i)
		CHKS(dut1[i] == 42, "The initializing constructor didn't initialize the vector entries correctly.");

	vector<int> dut2(dut1);
	CHKS(dut2.size() == dut1.size(), "The copy constructor did not create vectors of the same size.");
	CHKS(dut2.capacity() == dut1.capacity(), "The copy constructor did not create vectors of the same capacity.");
	for (size_t i = 0; i < dut2.size(); ++i)
		CHKS(dut2[i] == dut1[i], "The copy constructor din't initialize the vector entries correctly.");

	int dut3Array[] = {2,1,4,3,5};
	vector<int> dut3(dut3Array, dut3Array + sizeof(dut3Array)/sizeof(int));
	CHKS(dut3.size() == sizeof(dut3Array)/sizeof(int), "Iterator constructor: Did not create a vector of the correct size.");
	CHKS(dut3.capacity() >= sizeof(dut3Array)/sizeof(int), "Iterator constructor: Did not create a vector with enough capacity.");
	for (size_t i = 0; i < dut3.size(); ++i)
		CHKS(dut3[i] == dut3Array[i], "Iterator constructor: Did not initialize the vector entries correctly.");

	SUCCESSMSG("The constructor tests for vector<int> completed successfully!");

	TESTRETURN;
}


bool VectorIntInsertEraseTest()
{
	TESTINIT("Running rtl::vector<int> insertion tests.");

	int testInts[] = {2, 3, 4, 1, 2};
	size_t cTestInts = 5;
	int expected[] = {2, 3, 5, 4, 1, 2};
	size_t cExpected = 6;
	int expected2[] = {5, 2, 3, 4, 1, 2};
	int expected3[] = {2, 3, 4, 1, 2, 5};

	// Check inserting in the middle.
	vector<int> dut(testInts, testInts + sizeof(testInts)/sizeof(int));
	CHK(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts));

	vector<int>::iterator i = dut.begin();
	++i;
	++i;
	vector<int>::iterator result = dut.insert(i, 5);

	CHKS(i == result, "The iterator given to insert should match the returned iterator.");
	CHKS(*result == 5, "The inserted element was not correct.");
	CHKS(dut.size() == cExpected && std::equal(dut.begin(), dut.end(), expected),
		 "After middle insertion, the vector does not contain the expected values.");


	// Check erase
	dut.erase(result);
	CHKS(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts),
		 "After middle erase, the vector is not the original vector.");

	// Check inserting at the front.
	result = dut.insert(dut.begin(), 5);
	CHKS(*result == 5, "The inserted element was not correct.");
	CHKS(dut.size() == cExpected && std::equal(dut.begin(), dut.end(), expected2),
		 "After front insertion, the vector does not contain the expected values.");

	// Check erase
	dut.erase(result);
	CHKS(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts),
		 "After front erase, the vector is not the original vector.");

	// Check inserting at the end.
	result = dut.insert(dut.end(), 5);
	CHKS(*result == 5, "The inserted element was not correct.");
	CHKS(dut.size() == cExpected && std::equal(dut.begin(), dut.end(), expected3),
		 "After end insertion, the vector does not contain the expected values.");

	// Check erase
	dut.erase(result);
	CHKS(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts),
		 "After end erase, the vector is not the original vector.");

	SUCCESSMSG("The insertion tests for vector<int> completed successfully!");

	TESTRETURN;
}


bool VectorPushPopTest()
{
	TESTINIT("Running rtl::vector push/pop tests");


	// Push a couple of elements, and then pop them.  The RefCounter object
	// will at the very least verify that the resulting number of ctor and dtor
	// calls is as expected.
	vector<RefCounter> dut;
	{
		RefCounter obj(VerboseLogging::Enabled() /*enableLogging*/);
		dut.push_back(obj);
		dut.push_back(obj);
	}

	CHKS(dut.size() == 2, "The vector has the wrong size.");
	CHKS(RefCounter::GetCount() == 2, "push_back did not do construction properly.  Count is " << RefCounter::GetCount());

	dut.pop_back();
	dut.pop_back();

	CHKS(dut.size() == 0, "The vector has the wrong size.");
	CHKS(RefCounter::GetCount() == 0, "push_back did not do construction properly.  Count is " << RefCounter::GetCount());

	VRBSLOG("");

	// Start with a default list and add/remove elements.
	int testInts[] = {2,1,3,4,5};
	size_t testIntsSize = 5;
	int expected[] = {2,1,3,4,5,7,9};
	size_t expectedSize = 7;
	vector<int> dut1(testInts, testInts + sizeof(testInts)/sizeof(int));
	VRBSLOG("Created a vector of size " << dut1.size() << " when " << testIntsSize << " was expected.");
	CHKS(dut1.size() == testIntsSize, "push_back: iterator constructor didn't work.");

	dut1.push_back(7);
	VRBSLOG("Added 7 to the vector, and " << dut1.back() << " is there now.");
	dut1.push_back(9);
	VRBSLOG("Added 9 to the vector, and " << dut1.back() << " is there now.");

	VRBSLOG("Now the vector has " << dut1.size() << " objects and " << expectedSize << " was expected.");
	CHKS(dut1.size() == expectedSize, "push_back: push_back did not increase the vector size correctly.");
	CHKS(std::equal(dut1.begin(), dut1.end(), expected), "push_back did not modify the vector as expected.");

	dut1.pop_back();
	VRBSLOG("Popped 9 off; 7 should be the back and what's there is " << dut1.back());
	dut1.pop_back();
	VRBSLOG("Popped 7 off; 5 should be the back and what's there is " << dut1.back());

	CHK(dut1.size() == testIntsSize);
	CHKS(std::equal(dut1.begin(), dut1.end(), testInts), "pop_back did not modify the vector as expected.");


	SUCCESSMSG("The push/pop tests completed successfully.");

	TESTRETURN;
}



//
// RefCounter test class implementation
//

RefCounter::RefCounter(bool enableLogging /*= false*/) :
	m_enableLogging(enableLogging)
{
	PrintBeforeLog("\t(ctor): ");

	++s_count;

	PrintAfterLog();
}

RefCounter::RefCounter(const RefCounter& other) :
	m_enableLogging(other.m_enableLogging)
{
	PrintBeforeLog("\t(copyctor): ");

	++s_count;
	
	PrintAfterLog();
}

RefCounter::~RefCounter()
{
	PrintBeforeLog("\t(dtor): ");

	--s_count;

	PrintAfterLog();
}

void RefCounter::PrintBeforeLog(char* prefix /*= ""*/)
{
	if (m_enableLogging)
		std::cerr << prefix << "RefCount: The count was " << GetCount();
}

void RefCounter::PrintAfterLog()
{
	if (m_enableLogging)
		std::cerr << " and became " << GetCount() << std::endl;
}

/*static*/ int RefCounter::GetCount()
{
	return s_count;
}

int RefCounter::s_count = 0;


//
// VerboseLogging implementation
//

VerboseLogging::VerboseLogging()
{
	s_verboseLoggingEnabled++;
}

VerboseLogging::~VerboseLogging()
{
	s_verboseLoggingEnabled--;
}

/*static*/ bool VerboseLogging::Enabled()
{
	return s_verboseLoggingEnabled != 0;
}

/*static*/ int VerboseLogging::s_verboseLoggingEnabled = 0;

StopWatch::StopWatch() :
	m_startTickCount(0)
{
	Reset();
}

void StopWatch::Reset()
{
	m_startTickCount = ::GetTickCount64();
}

__int64 StopWatch::GetTickCount()
{
	return ::GetTickCount64() - m_startTickCount;
}


}
}