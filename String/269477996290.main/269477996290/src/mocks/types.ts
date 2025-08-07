import { ResourceType } from '@/types';

// 初始资源类型数据
export const initialResourceTypes: ResourceType[] = [
  {
    id: '1',
    name: '学术论文',
    description: '学术研究论文和期刊文章',
    createdAt: new Date('2025-01-15'),
    iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=academic%20paper%2C%20document%2C%20research%20icon&sign=359736457b2cbfcf17a3bc54b6f6befd'
  },
  {
    id: '2',
    name: '研究报告',
    description: '研究项目的进展报告和总结报告',
    createdAt: new Date('2025-01-15'),
    iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=research%20report%2C%20analysis%2C%20summary%20icon&sign=37af65167cef70a9d085941db333a19e'
  },
  {
    id: '3',
    name: '实验数据',
    description: '实验获得的原始数据和分析结果',
    createdAt: new Date('2025-01-15'),
    iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=experimental%20data%2C%20chart%2C%20statistics%20icon&sign=a2474a4072dca0633119a6e1aa4480fd'
  },
  {
    id: '4',
    name: '代码示例',
    description: '研究中使用的代码和示例程序',
    createdAt: new Date('2025-01-15'),
    iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=code%20example%2C%20programming%2C%20script%20icon&sign=441c26a1372160ff842a5a491176f8e7'
  },
  {
    id: '5',
    name: '会议资料',
    description: '学术会议的演示文稿和相关材料',
    createdAt: new Date('2025-01-15'),
    iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=meeting%20materials%2C%20presentation%2C%20conference%20icon&sign=d940565aebe947b4070821133a157c86'
  },
  {
    id: '6',
    name: '工具分享',
    description: '研究中使用的工具和软件推荐',
    createdAt: new Date('2025-01-15'),
    iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=tools%20sharing%2C%20software%2C%20utility%20icon&sign=228efbc52263bfba11a46257b4372d95'
  },
];

// 获取所有资源类型
export const getResourceTypes = (): ResourceType[] => {
  const storedTypes = localStorage.getItem('resourceTypes');
  return storedTypes ? JSON.parse(storedTypes) : initialResourceTypes;
};

// 保存资源类型
export const saveResourceTypes = (types: ResourceType[]): void => {
  localStorage.setItem('resourceTypes', JSON.stringify(types));
};

// 添加新资源类型
export const addResourceType = (type: Omit<ResourceType, 'id' | 'createdAt'>): ResourceType => {
  const types = getResourceTypes();
  const newType: ResourceType = {
    ...type,
    id: Date.now().toString(),
    createdAt: new Date(),
  };
  types.push(newType);
  saveResourceTypes(types);
  return newType;
};

// 删除资源类型
export const deleteResourceType = (id: string): void => {
  const types = getResourceTypes();
  const updatedTypes = types.filter(type => type.id !== id);
  saveResourceTypes(updatedTypes);
};