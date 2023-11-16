// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//		   The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.


        for (size_t i = 0; i < allProfiles.size(); ++i)
        {
            bool ok = true;

            for (size_t j = 0; j < bannedProfiles.size(); ++j)
            {
                if (allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name and
                    allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name and
                    allProfiles[i].m_age == bannedProfiles[j].m_age)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                Profile* copyProfile = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);

                try
                {
                    copyProfile->validateAddress();
                    result += copyProfile;
                    delete copyProfile;
                }
                catch (const std::string& eeh)
                {
                    delete copyProfile;
                    throw eeh;
                }
            }
        }

		return result;
	}
	
	DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//		   The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Smart Pointers.
        for (size_t i = 0; i < allProfiles.size(); ++i)
        {
            bool ok = true;

            for (size_t j = 0; j < bannedProfiles.size(); ++j)
            {
                if (allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name and
                    allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name and
                    allProfiles[i].m_age == bannedProfiles[j].m_age)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                std::unique_ptr<Profile> copyProfile = std::make_unique<Profile>(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);

                try
                {
                    copyProfile->validateAddress();
                    result += copyProfile;
                }
                catch (const std::string& eeh)
                {
                    throw eeh;
                }
            }
        }




		return result;
	}
}
