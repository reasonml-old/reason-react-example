let state =
  State.{
    title: "Kandan",
    volume: 0.75,
    lastVolume: 0.75,
    State.userId: Some 1,
    userMessageFocused: false,
    searchFormFocused: false,
    userMenuOpen: false,
    rightSidebarOpen: false,
    leftSidebarOpen: false,
    selectedChannelId: 2,
    users: [
      {id: 1, email: "sean@bushi.do", name: Some "Sean Grove", status: Online, username: "sgrove"},
      {
        id: 4,
        email: "dwwoelfel@gmail.com",
        name: Some "Daniel Woelfel",
        status: Online,
        username: "dww"
      },
      {
        id: 2,
        email: "info@sachagreif.com",
        name: Some "Sacha Greif",
        status: Away,
        username: "sg"
      },
      {id: 3, email: "sbensu@gmail.com", name: None, status: Offline, username: "sbensu"}
    ],
    channels: [
      {
        id: 0,
        title: "Classical",
        loading: false,
        userIds: State.UserIdSet.empty |> State.UserIdSet.add 1 |> State.UserIdSet.add 2,
        activities: [
          {userId: 3, content: "Move along", createdAt: 0.},
          {userId: 1, content: "Nothing to see here, eh?", createdAt: 1.},
          {
            userId: 1,
            content: "When are we going to get a more interesting lobby?",
            createdAt: 2.
          },
          {userId: 3, content: "Sir, move along", createdAt: 3.},
          {
            userId: 3,
            content: "This message contains the phrase \"search\" as the seventh to last word.",
            createdAt: 3.
          },
          {userId: 3, content: "Sir, move along", createdAt: 3.}
        ],
        media: {src: None, order: 0, duration: None},
        mediaState: Paused,
        mediaProgress: 0,
        playlist: [
          {
            src:
              Some "http://www.mfiles.co.uk/mp3-downloads/frederic-chopin-piano-sonata-2-op35-3-funeral-march.mp3",
            order: 0,
            duration: None
          },
          {
            src:
              Some "http://www.mfiles.co.uk/mp3-downloads/Dvorak-Symphony9-2-from-the-New-World.mp3",
            order: 1,
            duration: None
          },
          {
            src: Some "http://www.mfiles.co.uk/mp3-downloads/moonlight-movement1.mp3",
            order: 2,
            duration: None
          },
          {
            src:
              Some "http://www.mfiles.co.uk/mp3-downloads/beethoven-piano-sonata-pathetique-2.mp3",
            order: 3,
            duration: None
          }
        ]
      },
      {
        id: 1,
        title: "Trance",
        loading: false,
        activities: [
          {userId: 2, content: "Not enough progressive trance in here, really...", createdAt: 0.}
        ],
        userIds: State.UserIdSet.empty |> State.UserIdSet.add 1 |> State.UserIdSet.add 2,
        media: {src: None, order: 0, duration: None},
        mediaProgress: 0,
        mediaState: Paused,
        playlist: [
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/Gareth%20Emery%20feat.%20Christina%20Novelli%20-%20Concrete%20Angel.mp3",
            order: 0,
            duration: None
          }
        ]
      },
      {
        id: 2,
        title: "Lobby",
        loading: false,
        userIds:
          State.UserIdSet.empty |> State.UserIdSet.add 1 |> State.UserIdSet.add 2 |>
          State.UserIdSet.add 3 |>
          State.UserIdSet.add 4,
        activities: [
          {
            userId: 2,
            content: "> The ReasonCup logo http://reasoncup.com/resources/public/img/ReasonCup2016.png",
            createdAt: 1.
          },
          {userId: 1, content: "this is the last", createdAt: 99.},
          {
            userId: 1,
            content: "/me agrees with the previous message :+1: rgb(150,0,0) #000 #ff00ff",
            createdAt: 5.
          },
          {
            userId: 1,
            content: {|Paaassstttiiieee!!!

          Nice!
          ...right? |},
            createdAt: 4.
          },
          {
            userId: 1,
            content: "this is https://pbs.twimg.com/profile_images/766692876105289729/NZ16ZsLq_normal.jpg third",
            createdAt: 2.
          },
          {userId: 4, content: "this is second to last rgb(111,222,000)", createdAt: 3.},
          {userId: 4, content: "Reason will prevail!", createdAt: 9.},
          {userId: 4, content: "Right, @sgrove?", createdAt: 10.},
          {userId: 3, content: "If you can see this, SEARCH WORKS~~~!", createdAt: 100.}
        ],
        media: {src: None, order: 0, duration: None},
        mediaProgress: 0,
        mediaState: Paused,
        playlist: [
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/%E4%BA%B2%E7%88%B1%E7%9A%84%E4%BD%A0%E6%80%8E%E4%B9%88%E4%B8%8D%E5%9C%A8%E6%88%91%E8%BA%AB%E8%BE%B9.m4a",
            order: 0,
            duration: None
          },
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/%E5%A5%BD%E5%BF%83%E5%88%86%E6%89%8B%20Candy%20Lo%20feat.%20%E7%8E%8B%E5%8A%9B%E5%AE%8F.mp3",
            order: 1,
            duration: None
          },
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/Why%20This%20Kolaveri%20Di%20Full%20Song%20Promo%20Video%20in%20HD%20-%20.mp3",
            order: 2,
            duration: None
          },
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/%E4%BA%B2%E7%88%B1%E7%9A%84%20%EF%BC%8D%20%E5%BE%90%E8%8B%A5%E7%91%84.mp3",
            order: 3,
            duration: None
          },
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/Money%20Trees%20-%20Kendrick%20Lamar.mp3",
            order: 4,
            duration: None
          },
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/Armin%20van%20Buuren%20feat.%20Trevor%20Guthrie%20-%20This%20Is%20What%20It%20Feels%20Like.mp3",
            order: 5,
            duration: None
          },
          {
            src:
              Some "https://gp1.wpc.edgecastcdn.net/802892/http_private_production_west/songs/mp3_files/1499565/original/05_Last_Train_To_New_Jersey.mp3?e8817609673e6ceae29a01aebbc7efb2d22071b611f2c5d20b95874752890b0c4edd662116821b9083ff0faeaa15f2fd4e18d85478e697b4e0f50fc5404f165440cbf4d8a9da9a5843afbac36da6bc407e62d68502dff3e1510b7c2863ddb46a072c70740ad2d2cda77f3ce85e75b6dc01517324d33481daa7169fbf58b16d7108d36ad57945d3f0352d86322cc3fb302862b16711",
            order: 6,
            duration: None
          }
        ]
      }
    ],
    search: None
  };
