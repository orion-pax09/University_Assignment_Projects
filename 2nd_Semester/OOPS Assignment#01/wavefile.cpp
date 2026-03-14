
//code modified from: http://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file
//wav file from: https://aacapps.com/lamp/voices

#include <Windows.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef struct WAV_HEADER
{
    char                RIFF[4];        // RIFF Header      Magic header
    unsigned long       ChunkSize;      // RIFF Chunk Size  
    char                WAVE[4];        // WAVE Header      
    char                fmt[4];         // FMT header       
    unsigned long       Subchunk1Size;  // Size of the fmt chunk                                
    unsigned short      AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 
    unsigned short      NumOfChan;      // Number of channels 1=Mono 2=Sterio                   
    unsigned long       SamplesPerSec;  // Sampling Frequency in Hz                             
    unsigned long       bytesPerSec;    // bytes per second 
    unsigned short      blockAlign;     // 2=16-bit mono, 4=16-bit stereo 
    unsigned short      bitsPerSample;  // Number of bits per sample      
    char                Subchunk2ID[4]; // "data"  string   
    unsigned long       Subchunk2Size;  // Sampled data length    
} wav_hdr; 
void writeWavFile(const char* fileName, unsigned char* data, int length, int samplingRate)
{
    FILE* wavFile = fopen(fileName, "wb");

    if (!wavFile) {
        cout << "Error creating file!" << endl;
        return;
    }

    wav_hdr header;

    memcpy(header.RIFF, "RIFF", 4);
    memcpy(header.WAVE, "WAVE", 4);
    memcpy(header.fmt, "fmt ", 4);
    memcpy(header.Subchunk2ID, "data", 4);

    header.Subchunk1Size = 16;
    header.AudioFormat = 1;
    header.NumOfChan = 1;
    header.SamplesPerSec = samplingRate;
    header.bitsPerSample = 8;
    header.bytesPerSec = samplingRate * header.NumOfChan * header.bitsPerSample / 8;
    header.blockAlign = header.NumOfChan * header.bitsPerSample / 8;

    header.Subchunk2Size = length;
    header.ChunkSize = 36 + length;

    fwrite(&header, 1, sizeof(header), wavFile);
    fwrite(data, 1, length, wavFile);

    fclose(wavFile);

    cout << "New WAV file written successfully: " << fileName << endl;
}
bool readWavFile(char *fileName, unsigned char data[], int &length, int &samplingRate)
{
    FILE *wavFile;
    int headerSize = sizeof(wav_hdr);
    bool success = false;
    
    // Open file in binary mode for reading
    wavFile = fopen(fileName, "rb");
    if (wavFile)
    {
        wav_hdr wavHeader;
        
        // Read the header
        size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
        
        if (bytesRead == headerSize)
        {
            // Verify it's a valid WAV file (check RIFF and WAVE markers)
            if (memcmp(wavHeader.RIFF, "RIFF", 4) == 0 && 
                memcmp(wavHeader.WAVE, "WAVE", 4) == 0)
            {
                // Display WAV file information
                cout << "\nWAV File Information:" << endl;
                cout << "====================" << endl;
                cout << "File: " << fileName << endl;
                cout << "Total Data Size: " << wavHeader.Subchunk2Size << " bytes" << endl;
                cout << "Bits per sample: " << wavHeader.bitsPerSample << endl;
                cout << "Bytes per second: " << wavHeader.bytesPerSec << endl;
                cout << "Number of channels: " << wavHeader.NumOfChan << endl;
                cout << "Sample Rate: " << wavHeader.SamplesPerSec << " Hz" << endl;
                cout << "Audio Format: " << (wavHeader.AudioFormat == 1 ? "PCM" : "Other") << endl;
                cout << "====================" << endl;
                
                // Calculate how much data to read (don't exceed buffer)
                int dataToRead = wavHeader.Subchunk2Size;
                if (dataToRead > length)
                {
                    cout << "Warning: Buffer size (" << length << ") is smaller than audio data (" 
                         << dataToRead << "). Truncating to buffer size." << endl;
                    dataToRead = length;
                }
                
                // Read the audio data
                size_t dataRead = fread(data, 1, dataToRead, wavFile);
                length = dataRead;  // Update actual bytes read
                samplingRate = wavHeader.SamplesPerSec;
                success = true;
                
                cout << "Successfully read " << dataRead << " bytes of audio data" << endl;
                
                // Show first few samples as preview
                cout << "\nFirst 20 samples (as decimal values):" << endl;
                for (int i = 0; i < 20 && i < dataRead; i++)
                {
                    cout << (int)data[i] << " ";
                    if ((i + 1) % 10 == 0) cout << endl;
                }
                cout << endl;
            }
            else
            {
                cout << "Error: Not a valid WAV file (missing RIFF or WAVE marker)!" << endl;
            }
        }
        else
        {
            cout << "Error: Could not read WAV header! Read " << bytesRead 
                 << " bytes, expected " << headerSize << " bytes." << endl;
        }
        
        fclose(wavFile);
    }
    else
    {
        cout << "Error: Could not open file '" << fileName << "'" << endl;
    }
    
    return success;
}


void allocate(unsigned char*& arr, int size) 
{
    arr = new unsigned char[size];
    cout << "Allocated " << size << " bytes of memory" << endl;
}


void deallocate_memory(unsigned char*& arr) 
{
    if (arr != nullptr) 
    {
        delete[] arr;
        arr = nullptr;
        cout << "Memory deallocated" << endl;
    }
}


// Duplicating function
unsigned char* double_Array(const unsigned char* arr, int size){
    int newsize = 2*size;
    unsigned char* copy = new unsigned char [newsize];
    for (int i = 0 ; i < size && i < 40; i++){
        copy[2*i] = arr[i];
        copy[2*i+1] = arr[i];
    }
    return copy;   
}


unsigned char* shrinking_Array(const unsigned char* arr , int size){
    int new_Size = size / 2;
    if (size % 2 == 1){
        new_Size = (size + 1) / 2;
    }
    unsigned char* shrinkarray = new unsigned char[new_Size];
    for (int i = 0 ; i < new_Size  ; i++){
        shrinkarray[i] = arr[i*2];
    }
    return shrinkarray;
}


unsigned char* fillwithmean(const unsigned char* arr , unsigned char* copy, int size , int N){
    for (int i = 0; i < size; i++)
	{
		int start = i - N;
		int end = i + N;

		if (start < 0) start = 0;
		if (end >= size) end = size - 1;

		double sum = 0.0;
		int count = 0;

		for (int j = start; j <= end; j++)
		{
			sum += arr[j];
			count++;
		}

		copy[i] = sum / count;
	}

	return copy;
}


void readfilename(const string& Filename, unsigned char* arr , int size , int& samplingrate){
    bool loaded_file = readWavFile(const_cast<char*>(Filename.c_str()),arr,size ,samplingrate);
    if (loaded_file){
        cout<< "--------- "<< Filename <<" been read successfully "<< "-----------"<<endl;
    }
    else{
        cout << "File has not been read succesfully"<<endl;
    }
}


void upSampleaudio(string& filename,unsigned char* arr,int size,int samplingrate)
{

    // doubling the size of audiofile and samplingrate to change pitch
    int sampling_rate = 2*sampling_rate;
    int newsize = 2*size;

    // Duplicating samples
    unsigned char* upsampling = double_Array(arr, size);

    // Creating new filename
    string newFile = "upsampled_" + filename;

    // Writi new WAV file
    writeWavFile(newFile.c_str(),upsampling,newsize,sampling_rate);
    delete[] upsampling;
    upsampling = nullptr;
}


void downsampleaudio(string& filename , unsigned char* arr , int size , int samplingrate){
    int new_Size = (size+1) / 2;
    int newsampling = samplingrate / 2;
    unsigned char* downsampling = shrinking_Array(arr , size);
    string newfilename = "Downsample_" + filename;
    writeWavFile(newfilename.c_str(),downsampling , new_Size ,newsampling);
    delete [] downsampling;
    downsampling = nullptr;
}


void averagefilterfile(string&filename , unsigned char* arr , int size, int& sampling_rate, int n){
    unsigned char* averagefilterfile = new unsigned char [size];
    fillwithmean(arr,averagefilterfile,size, n);
    string Newfile = "average_" + to_string(n) + filename ;
    writeWavFile(Newfile.c_str(),averagefilterfile, size ,sampling_rate);
    delete[]averagefilterfile;
    averagefilterfile = nullptr;
}

unsigned char* mergearray(unsigned char* arr1 , int size1 , unsigned char* arr2 , int size2,int &newsize){
    newsize= size1 + size2;
    unsigned char* thirdarray = new unsigned char [newsize];
    int i = 0 ;
    int j = 0;
    int k = 0;
    // step 4: all element from array 1 and array 2 of both file is copied to third array
    while (i < size1 && j < size2){
        thirdarray[k++] = arr1[i++];
        thirdarray[k++]= arr2[j++];
    }

    /* if there is remaining bytes data that has not been yet copied in third array and this 
    while condition makes sure to copy all data*/
    
    while (i < size1){
        thirdarray[k++] = arr1[i++];
    }
    while (j < size2){
        thirdarray[k++] = arr2[j++];
    }
    return thirdarray;
}

int main() {
    const int N = 2;
    unsigned char* audiodata = nullptr;
    int Datalength = 1000000;
    int sampling_rate = 0;

    string filename;

    cout << "Enter the file following: "<<endl;
    cout << "1. For Sallimono.wav file"<<endl;
    cout << "2. For song.wav file"<<endl;
    cout << "3. For dhani.wav file"<<endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    if(choice == 1){
    filename = "sallimono.wav";
    readfilename(filename , audiodata , Datalength , sampling_rate);
    }
    else if(choice == 2){
    filename = "song.wav";
    readfilename(filename , audiodata , Datalength , sampling_rate);
    } 
    else if(choice == 3){
    filename = "dhani.wav";
    readfilename(filename , audiodata , Datalength , sampling_rate);
    }
    else return 0;


    allocate(audiodata, Datalength);

    bool loaded = readWavFile(const_cast<char*>(filename.c_str()),audiodata, Datalength, sampling_rate);

    if (!loaded) {
        deallocate_memory(audiodata);
        return 0;
    }


    cout << "------------------------------------Duplicated array-------------------------------"<<endl;
    unsigned char* duplicate_Array = double_Array(audiodata, Datalength);
    for (int i = 0 ; i < Datalength && i < 40 ; i++){
        cout << (int) duplicate_Array[i]<<" ";
    }
    cout << endl;


        cout << "------------------------------------Shrink array-------------------------------"<<endl;
    unsigned char* shrink_Array = shrinking_Array(audiodata, Datalength);
    for (int i = 0 ; i < Datalength && i < 10 ; i++){
        cout << (int) shrink_Array[i] <<" ";
    }
    cout << endl;


    unsigned char* average_Array = new unsigned char[Datalength];
    cout << "--------------------Average value of each index with N: "<<N<<"--------------------"<<endl;
    fillwithmean(audiodata, average_Array, Datalength, 2);
    for (int i = 0 ; i < Datalength && i < 10 ; i++){
        cout <<(int) average_Array[i]<<" ";
    }
    cout << endl;

    upSampleaudio(filename , audiodata , Datalength , sampling_rate);
    cout <<endl;


    downsampleaudio(filename , audiodata , Datalength , sampling_rate);
    cout << endl;
    
    cout << "----------------Filtering average value of each elements in array of file-------------------------"<<endl;

    averagefilterfile(filename , audiodata , Datalength , sampling_rate , N);

    // step 1: making 2 different audiodata for sallimono and dhani to merge array

    int mergesize;
    unsigned char* audiodata1 = nullptr;
    int datasize_salli = 180001;
    int sallisampling=0;
    unsigned char* audiodata2 = nullptr;
    int datasize_dhani = 2950144;
    int dhanisampling=0;

    // step 2: allocating memory for array for sallimono.wav and dhani.wav file


    allocate(audiodata1,datasize_salli);
    allocate(audiodata2,datasize_dhani);

    // step 3: read both dhani and sallimono file with new audiodata array
    cout<< "--------------------------------Merging Array--------------------------------"<<endl;
    readfilename("sallimono.wav" , audiodata1 , datasize_salli , sallisampling);
    readfilename("dhani.wav" , audiodata2 , datasize_dhani , dhanisampling);

    // step 4: call merge array function with passing new audiodata as new array parameter
    unsigned char* merging_Array = mergearray(audiodata1 , datasize_salli , audiodata2 , datasize_dhani,mergesize);

    writeWavFile("merged_sallimono.wav" , merging_Array , mergesize , sallisampling );
    writeWavFile("merged_dhani.wav" , merging_Array , mergesize , dhanisampling );


    delete[] duplicate_Array;
    duplicate_Array = nullptr;

    delete[] shrink_Array;
    shrink_Array = nullptr;

    delete[] average_Array;
    average_Array = nullptr;

    delete [] merging_Array;
    merging_Array = nullptr;

    deallocate_memory(audiodata);
    // deallocate memory for sallimono and dhani merged array audiodata
    deallocate_memory(audiodata1);
    deallocate_memory(audiodata2);
}
