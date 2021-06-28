from riotwatcher import LolWatcher, ApiError

watcher = LolWatcher('RGAPI-c5bb2107-69c6-4fc7-a43a-f162ad502f9c')

my_region = 'na1'

#Get latest version of game from data dragon
versions = watcher.data_dragon.versions_for_region(my_region)
champ_versions = versions['n']['champion']

#Get all champs' info
cur_champ_list = watcher.data_dragon.champions(champ_versions)

name = input("Summoner name?\n")

me = watcher.summoner.by_name(my_region, name)

my_ranked = watcher.league.by_summoner(my_region, me['id'])

my_matches = watcher.match.matchlist_by_account(my_region, me['accountId'], begin_index=0, end_index=100)

for id in my_matches['matches']:
    print(id)
    champID = id['champion']
    for champ in cur_champ_list['data']:
        key = cur_champ_list['data'][champ]['key']
        if key == str(champID):
            print(cur_champ_list['data'][champ]['id'])

match = watcher.match.timeline_by_match(my_region, 3672685049)

print(match)

