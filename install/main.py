import requests
from tqdm import tqdm
from pathlib import Path


def doparse(pathtodb_):
    MaxNumberOfUrls = 395
    # 395
    for i in tqdm(range(MaxNumberOfUrls + 1)):
        line = '{:0>5}'.format(i)
        url = 'https://virusshare.com/hashfiles/VirusShare_' + line + '.md5'
        req = requests.get(url)
        rawdb = req.text
        i = 0
        while i < 6:
            rawdb = rawdb[33:]
            i += 1
        with open(pathtodb_, 'a') as output_file:
            output_file.write(rawdb)


if __name__ == '__main__':
    repopath = Path(__file__).parent.absolute().parent
    pathtodb = repopath.joinpath("DataBaseFiles/DataBase.db")
    doparse(pathtodb)
